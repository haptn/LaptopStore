//#include <stdio.h>
//int main()
//{	
////	char enter = '\n';
////	printf("Thank you. Your bill will be shown after 'Enter'.");
////	scanf("\n");
////	printf("Hello!");	
////	return 0;
//}

//#include <conio.h>
//#include <stdio.h>
//#include <time.h>
//#include <dos.h>
 
//void main()
//{
//      struct time x;
//      struct date y;
//      int gio,phut,giay;
//      int ngay,thang,nam;
//      gettime(&x);
//      gio=x.ti_hour;
//      phut=x.ti_min;
//      giay=x.ti_sec;
//      printf("Bay gio la:   %02d:%02d:%02d",gio,phut,giay);
//      textcolor(10);
//      //lay ngay;
//      getdate (&y);
//      nam=y.da_year;
//      thang=y.da_mon;
//      ngay=y.da_day;
//      printf("\nHom nay : ngay  %02d   thang %02d  nam  %02d\n",ngay,thang,nam);
// 
//      getch();
//}


//int main ()
//{
//	int day, month, year;
//    time_t rawtime;
//    struct tm * timeinfo;
//    time (&rawtime);
////   timeinfo = localtime (&rawtime);
////    printf ("Thoi gian va ngay hien hanh cua he thong: %s", asctime (timeinfo));
//	day = timeinfo.tm_mday;
//	month = timeinfo.tm_mon;
//	year = timeinfo.tm_year;
//	printf ("Thoi gian va ngay hien hanh cua he thong: %d/%d/%d.", day, month, year);
//    getch();
//    return 0;
//}

//int main()
//{
//	struct tm time;
//	_getsystime(&time);
//}

/* CÁC L?NH TI?N CH? TH? G?I CÁC T?P THU VI?N CHU?N */
#include <stdio.h>
#include <stdlib.h>	
#include <string.h>	
#include <conio.h>	
#include <time.h>	

struct date
{
	int ngay;
	int thang;
	int nam;
};

typedef struct date Date;

int main(int argc, char *argv[])
{
	printf("\n\t CHU'O'NG TRI`NH TRUY CAP NGAY GIO' HE THONG \n");
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	printf("\n Thoi Gian Hien Tai (nam-thang-ngay): %d/%d/%d\n", tm.tm_mday, tm.tm_mon +1, tm.tm_year +1900);
	
	Date d;
	d.ngay = tm.tm_mday;
	d.thang = tm.tm_mon +1;
	d.nam = tm.tm_year +1900;
	printf("\n struct Date.ngay = %d, Date.thang = %d, Date.nam = %d", d.ngay, d.thang, d.nam);
	
	getch();
	return EXIT_SUCCESS;
}
