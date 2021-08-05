#include <stdio.h>
const int S_PER_M = 60;			// количество секунд в минуте
const int S_PER_H = 3600;		// количество секунд в часе
const double M_PER_K = 0.62137; // количество миль в километре

int running(void) {
	double distk, distm; // дистанция пробега в километрах и милях
	double rate; 		 // средняя скорость в милях в час
	int min, sec;		 // время пробега в минутах и секундах
	int time;			 // время пробега только в секундах
	double mtime;		 // время пробега одной мили в секундах
	int mmin, msec;		 // время пробега одной мили в минутах и секундах
	
	printf("This is program transform running time of distance in metric system\n");
	printf("  during running one mile and calculate your average ");
	printf("speed in miles in hour.\n");
	printf("Enter distance running in kilometers:\n");
	scanf("%lf", &distk); // %lf для типа double
	printf("Enter time in minutes and seconds.\n");
	printf("Start entering from minutes:\n");	
	scanf("%d", &min);
	printf("Now enter seconds:\n");
	scanf("%d", &sec);
	// переводит время в секунды
	time = S_PER_M * min + sec;
	// переводит километры в мили
	distm = M_PER_K * distk;
	// умножение миль в секунду на количество секунд в часе дает количество миль в час
	rate = distm / time * S_PER_H;
	// деление времени на расстояние дает время пробега одной мили
	mtime = (double) time / distm;
	mmin = (int) mtime / S_PER_M; // вычисление полного количества минут
	msec = (int) mtime % S_PER_M; // вычисление полного количества секунд
	printf("You are running %1.2f km (%1.2f miles) in %d min, %d sec.\n",
		distk, distm, min, sec);
	printf("This speed corresponds running one miles in %d min, ", mmin);
	printf("%d sec.\nYour average speed equals %1.2f miles in hours.\n", msec, rate);
	
	return 0;
}	
