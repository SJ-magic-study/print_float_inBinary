/************************************************************
************************************************************/
#include <stdio.h>
#include <stdlib.h>

// #define CHAR_BIT 8
#include <limits.h> 

/************************************************************
浮動小数点数の内部表現を取得してみよう
	https://qiita.com/nia_tn1012/items/d26f0fc993895a09b30b
************************************************************/
union FLOAT_INT{
	float f;
	int i;
};

void print_floatPattern(FLOAT_INT a)
{
	int c = 0;
    for(int i = 31; 0 <= i; i-- ){
        printf( "%d", ( a.i >> i ) & 1 );
		c++;
		if( (c == 1) || (c == 9) ) printf("|");
    }
    printf( "\n" );
}

int main(int argc, char** argv)
{
	/********************
	********************/
	float t = 0;
	float dt = 1.0/44100.0;
	
	if(2 <= argc) t = atof(argv[1]);
	
	printf("> sizeof float = %d, int = %d\n", sizeof(float), sizeof(int));
	printf("\n%f + %f = %f\n", t, dt, t + dt);
	
	/********************
	********************/
	FLOAT_INT val;
	val.f = dt;
	print_floatPattern(val);
	
	/********************
	********************/
	printf("\nGood-bye\n");
	
	return 0;
}

