#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void main(){
	int ch=0;
	do{
		printf("1. Basic Arithmetic Operations\n2. Trigonometric Calculations\n");
		printf("3. Logarithmic Calculations\n4. Square root\n5. Exit\n\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the expression in this format: \n");
				printf("(operand1)(operator)(operand2)\n");
				float a,b; char opr;
				scanf("%f%c%f",&a,&opr,&b);
				if(opr=='+')
					printf("%.2f%c%.2f=%.2f\n\n",a,opr,b,(a+b));
				else if(opr=='-')
					printf("%.2f%c%.2f=%.2f\n\n",a,opr,b,(a-b));
				else if(opr=='*')
					printf("%.2f%c%.2f=%.2f\n\n",a,opr,b,(a*b));
				else if(opr=='/'){
					if(b==0){ printf("Divide by zero error!!!\n");exit(-1); }
					printf("%.2f%c%.2f=%.2f\n\n",a,opr,b,(a/b));
				}
				else
					printf("Wrong input!!\n");
				break;
			case 2:
				printf("1. sin(X)\n2. cos(X)\n3. tan(X)\n4. sec(X)\n5. cosec(X)\n6. cot(X)\n\n");
				printf("Enter your choice: ");
				int cht;
				scanf("%d",&cht);
				if(cht>7 || cht<=0){ printf("Wrong choice!!!\n"); exit(-1);  }
				printf("Enter the angle in degrees: ");
				float deg,n; scanf("%f",&deg);
				float rad=deg*3.14/180;
				if(cht==1)	printf("sin(%.0f)=%.2f\n\n",deg,sin(rad));
				else if(cht==2)	printf("cos(%.0f)=%.2f\n\n",deg,cos(rad));
				else if(cht==3)	printf("tan(%.0f)=%.2f\n\n",deg,tan(rad));
				else if(cht==4)	printf("sec(%.0f)=%.2f\n\n",deg,1/cos(rad));
				else if(cht==5)	printf("cosec(%.0f)=%.2f\n\n",deg,1/sin(rad));
				else if(cht==6)	printf("cot(%.0f)=%.2f\n\n",deg,1/tan(rad));
				break;
			case 3:
				//float n;
				printf("1. Natural Logarithm\n2. Logarithm to base 10\n");
				scanf("%d",&cht);
				if(cht>2||cht<=0) { printf("Wrong choice!!\n");	exit(-1); }
				printf("Enter the value for which the logarithm has to be found: ");
				scanf("%f",&n);
				if(cht==1) printf("ln(%.2f)=%.2f\n\n",n,log(n));
				if(cht==2) printf("log(%.2f)=%.2f\n\n",n,log(n)/2.303);
				break;
			case 4:
				//float n;
				printf("Enter the number for which the square root has to be computed: ");
				scanf("%f",&n);
				printf("sqrt(%.2f)=%.2f\n\n",n,sqrt(n));
				break;
			default:
				if(ch!=5)
					printf("Wrong Input!!!\n");
				break;
		}
	}while(ch!=5);
}
