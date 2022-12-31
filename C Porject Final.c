#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<conio.h>

char name[100];

int choice1,choice2,choice3;
char choice1_c[10],choice2_c[10],choice3_c[10];

int points;

char input_numerical_lotto_1[10];
char input_numerical_lotto_2[10];
char input_numerical_lotto_3[10];
char input_numerical_lotto_4[10];
char input_numerical_lotto_5[10];
char input_numerical_lotto_6[10];

char input_lucky_ball_1[10];
char input_lucky_ball_2[10];
char input_lucky_ball_3[10];
char input_lucky_ball_4[10];
char input_lucky_ball_5[10];
char input_lucky_ball_extraa[10];

char input_super_lotto_1[10];
char input_super_lotto_2[10];
char input_super_lotto_3[10];
char input_super_lotto_4[10];
char input_super_lotto_5[10];
char input_super_lotto_6[10];

int numerical_lotto[6];
int numerical_lotto_number[6];
int numerical_lotto_point = 0;

int lucky_ball[6];
int lucky_ball_number[5];
int lucky_ball_number_extra;
int lucky_ball_point;

int super_lotto[6];
int super_lotto_number[6];
int super_lotto_point = 0;

int true_control = 0;
int multiplier;

int random;

bool unique;

int extra;
int extra_true_control;

int array_stl[6];
int array_lts[6];
int stl_variable;
int lts_variable;

int digit_check_counter;
int random_counter_1;
int random_counter_2;
int toint_counter;
int orderstl_counter_1;
int orderstl_counter_2;
int orderlts_counter_1;
int orderlts_counter_2;
int point_counter_1;
int point_counter_2;
int welcome_counter=0;
int user_counter;
int score_file;
int score;
char empty[10];
char mode_c[10];
char reset;
char sure;
int mode;

bool digit_check(char key[])//Number check function
{
    for(digit_check_counter = 0; digit_check_counter < strlen(key); digit_check_counter++)
    {
        if(isdigit(key[digit_check_counter])==0)//if isdigit function is zero input is not number if bigger than zero input is number
        {
        	system ("cls");
        	printf("\t\t\t\t\tPlease enter a valid number!\n\n");
            return false;
        }
    }
    system ("cls");
    return true;
}

int main()
{
	if(welcome_counter==0){
		
	printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\tW     W   EEEEE  L       CCCCC    OOOO     M     M   EEEEE\n");
    printf("\t\t\t\tW     W   E      L      C        O    O    MM   MM   E    \n");
    printf("\t\t\t\tW  W  W   EEE    L      C        O    O    M  M  M   EEE  \n");
    printf("\t\t\t\tWW   WW   E      L      C        O    O    M     M   E    \n");
    printf("\t\t\t\tW     W   EEEEE  LLLLL   CCCCC    OOOO     M     M   EEEEE\n");
    printf("\n\n");
    
    Sleep(3500);//3.5 second delay
    welcome_counter++;//This counter is for this part to appear only once when the application starts
    system("cls");
	}

	do{
	printf("\t\t\t\t\t LOTTERY GAMES\n\n");
	printf("\t\t\t\t\t 1.  Play Numerical Lotto\n");
	printf("\t\t\t\t\t 2.  Play Lucky Ball\n");
	printf("\t\t\t\t\t 3.  Play Super Lotto\n");
	printf("\t\t\t\t\t 4.  View Past Records\n");
	printf("\t\t\t\t\t 5.  Theme Settings \n");
	printf("\t\t\t\t\t 6.  Exit\n\n");
    printf("\t\t\t\t\t (Your total reward: %d points)\n\n\t\t\t\t\t Enter You Choice:",points);
    scanf("%s",&choice1_c);
	}
  	while (!digit_check(choice1_c));
  	
	choice1=toint(choice1_c);//Convert char input to integer
	
	while(choice1>6||choice1<1){
		printf("\t\t\t\t\tPlease enter a valid number!\n\n");
		main();
	}
		
	system ("cls");//CLEAR SCREEN
		
	switch (choice1){
		
			
		case 1://NUMERICAL LOTTO GAME
			
			Numerical_Lotto();
			
			
		case 2://LUCKY BALL GAME
			
			Lucky_Ball();
			
			
		case 3://SUPER LOTTO GAME
			
			Super_Lotto();
			
		case 4://View Past Records

			flag5:
				
			ViewRecord();
			printf("\n\t\t\t\t\t   Press any key to continue");
			printf("\n\n\t\t\t\t         (Press \"d\" to delete all saves)");
			reset=getch();//The program continues when the user presses any key
			switch(reset){
				
				case 'd':
					
					printf("\n\t\t\t\t\t    Are you sure? (y / n)");
					sure=getch();
					
					switch(sure){
				
						case 'y':
							
							DeleteSaves();
						
						case 'n':
							
							system("cls");
							goto flag5;
							
						default:
							
							system("cls");
							goto flag5;
					
					}
					
				default:
					system ("cls");
					main();
					
					
			}
   			
			
		case 5://Theme settings

			settings();
			
			
		case 6:// Exit

			exit(0);
			
	}

}

int Numerical_Lotto(){
	
			//RANDOM NUMBER FUNCTION
			srand(time(NULL));
			
			for (random_counter_1 = 0; random_counter_1 < 6; random_counter_1++)
  			{
   				do
  				{
      			random = (rand() % 49) + 1;
     			unique = true;
      			for (random_counter_2 = 0; random_counter_2 < random_counter_1; random_counter_2++)
       			if (numerical_lotto[random_counter_2] == random) unique = false;
   				} 
				while (!unique);
   				numerical_lotto[random_counter_1] = random;
			}
			//USER INPUTS
   			do{
       		printf("\t\t\t\t\tInput a number 1 [1-49]: ");
     		scanf("%s",input_numerical_lotto_1);        //GET NUMBER FROM USER
     		numerical_lotto_number[0] = toint(input_numerical_lotto_1);
			 }
  			while (!digit_check(input_numerical_lotto_1)||numerical_lotto_number[0]>49||numerical_lotto_number[0]<1);//CHECK "CHAR" OR "INT" and within the range games want.
  			
   			do{
       		printf("\t\t\t\t\tInput a number 2 [1-49]: ");
     		scanf("%s",input_numerical_lotto_2);
     		numerical_lotto_number[1] = toint(input_numerical_lotto_2);
			 }
  			while (!digit_check(input_numerical_lotto_2)||numerical_lotto_number[1]>49||numerical_lotto_number[1]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 3 [1-49]: ");
     		scanf("%s",input_numerical_lotto_3);
     		numerical_lotto_number[2] = toint(input_numerical_lotto_3);
			 }
  			while (!digit_check(input_numerical_lotto_3)||numerical_lotto_number[2]>49||numerical_lotto_number[2]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 4 [1-49]: ");
     		scanf("%s",input_numerical_lotto_4);
     		numerical_lotto_number[3] = toint(input_numerical_lotto_4);
			 }
  			while (!digit_check(input_numerical_lotto_4)||numerical_lotto_number[3]>49||numerical_lotto_number[3]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 5 [1-49]: ");
     		scanf("%s",input_numerical_lotto_5);
     		numerical_lotto_number[4] = toint(input_numerical_lotto_5);
			 }
  			while (!digit_check(input_numerical_lotto_5)||numerical_lotto_number[4]>49||numerical_lotto_number[4]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 6 [1-49]: ");
     		scanf("%s",input_numerical_lotto_6);
     		numerical_lotto_number[5] = toint(input_numerical_lotto_6);
			 }
  			while (!digit_check(input_numerical_lotto_6)||numerical_lotto_number[5]>49||numerical_lotto_number[5]<1);
    		
    		system ("cls");//CLEAR SCREEN

			//CONVER USER INPUTS TO INT
    		numerical_lotto_number[0] = toint(input_numerical_lotto_1);
    		numerical_lotto_number[1] = toint(input_numerical_lotto_2);
    		numerical_lotto_number[2] = toint(input_numerical_lotto_3);
    		numerical_lotto_number[3] = toint(input_numerical_lotto_4);
    		numerical_lotto_number[4] = toint(input_numerical_lotto_5);
    		numerical_lotto_number[5] = toint(input_numerical_lotto_6);
    		
    		//True check
    		for(point_counter_1=0; point_counter_1 < 6; point_counter_1++){
    			int found = 0;
            	for(point_counter_2=0; point_counter_2 < 6; point_counter_2++){ 
                  	if(numerical_lotto_number[point_counter_2] == numerical_lotto[point_counter_1]){
                  		if(!found){
						  true_control++;
                          found = 1;
                   		}
                    	break;
                	}
           		}
           	}
    		
			//POINT CALCULATIONS
			if(true_control >= 3){
				
				multiplier=true_control-2 ;
				numerical_lotto_point = 16 * pow(2,multiplier);
				points = points+numerical_lotto_point;
			}
			else{
				numerical_lotto_point = 0;

			}
			
			//PRINT RANDOMS AND GAINED POINT
			printf("\t\t\t\t\tLucky Numbers:  ");	
			orderstl(numerical_lotto,6);//Go to order function and sorted numbers are printed in this function
			printf("\n");
			printf("\t\t\t\t\tYour Numbers:   ");
			orderstl(numerical_lotto_number,6);//Go to order function and sorted numbers are printed in this function
			printf("\n");
			printf("\t\t\t\t\tTrue: %d  ",true_control);
     		printf("\n\n");
			printf("\t\t\t\t\t%d points earned! \n\n",numerical_lotto_point);//PRINT POINTS GAINED FROM ONLY THIS GAME
			numerical_lotto_point = 0;		//RESET POINT GAINED FROM ONLY THIS GAME
			true_control = 0;				//RESET TRUES OF THIS GAME
							
			flag1:
			//AFTER GAME MENU
			do{
   			printf("\t\t\t\t\t1.Try Again\n\t\t\t\t\t2.Main Menu\n\t\t\t\t\t3.Save\n\t\t\t\t\t4.Exit\n");
   			printf("\t\t\t\t\t");
    		scanf("%s",&choice2_c);
			}
  			while (!digit_check(choice2_c));
			choice2=toint(choice2_c);
			while(choice2>4||choice2<1){
			printf("\t\t\t\t\tPlease enter a valid number!\n\n");
			goto flag1;
			}
			
			//AFTER GAME MENU SELECTIONS
			switch(choice2){
				
				case 1:
					
					system("cls");
					Numerical_Lotto();//GO BACK TO NUMERICAL NUMBER FUNCTION FOR TRY AGAIN
					
				case 2:
					
					system("cls");
					main();//GO BACK TO MAIN FUNCTION FOR MAIN MENU
					
				case 3:
					
					Record(points);//Go to Record function for save our total points
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Successfully saved!\n\n");//Print "Successfully saved!" 
					Sleep(2000);//2 second delay
					system("cls");//Clear screen
					main();//Go to main function
					
				case 4:
					
					exit(0);
					
			}
}

int Lucky_Ball(){
				
			//RANDOM NUMBER FUNCTION
			srand(time(NULL));
			
			for (random_counter_1 = 0; random_counter_1 < 5; random_counter_1++)
  			{
   				do
  				{
      			random = (rand() % 35) + 1;
     			unique = true;
      			for (random_counter_2 = 0; random_counter_2 < random_counter_1; random_counter_2++)
       			if (lucky_ball[random_counter_2] == random) unique = false;
   				} 
				while (!unique);
   				lucky_ball[random_counter_1] = random;
			}
			
			for (random_counter_1 = 0; random_counter_1 < 1; random_counter_1++)
  			{
   				do
  				{
      			random = (rand() % 14) + 1;
     			unique = true;
      			for (random_counter_2 = 0; random_counter_2 < random_counter_1; random_counter_2++)
       			if (extra == random) unique = false;
   				} 
				while (!unique);
   				extra = random;
			}
			
			//USER INPUTS
   			do{
       		printf("\t\t\t\t\tInput a number 1 [1-35]: ");
     		scanf("%s",input_lucky_ball_1);
     		lucky_ball_number[0] = toint(input_lucky_ball_1);
			 }
  			while (!digit_check(input_lucky_ball_1)||lucky_ball_number[0]>35||lucky_ball_number[0]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 2 [1-35]: ");
     		scanf("%s",input_lucky_ball_2);
     		lucky_ball_number[1] = toint(input_lucky_ball_2);
			 }
  			while (!digit_check(input_lucky_ball_2)||lucky_ball_number[1]>35||lucky_ball_number[1]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 3 [1-35]: ");
     		scanf("%s",input_lucky_ball_3);
     		lucky_ball_number[2] = toint(input_lucky_ball_3);
			 }
  			while (!digit_check(input_lucky_ball_3)||lucky_ball_number[2]>35||lucky_ball_number[2]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 4 [1-35]: ");
     		scanf("%s",input_lucky_ball_4);
     		lucky_ball_number[3] = toint(input_lucky_ball_4);
			 }
  			while (!digit_check(input_lucky_ball_4)||lucky_ball_number[3]>35||lucky_ball_number[3]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 5 [1-35]: ");
     		scanf("%s",input_lucky_ball_5);
     		lucky_ball_number[4] = toint(input_lucky_ball_5);
			 }
  			while (!digit_check(input_lucky_ball_5)||lucky_ball_number[4]>35||lucky_ball_number[4]<1);

   			do{
       		printf("\t\t\t\t\tInput extra number [1-14]: ");
     		scanf("%s",input_lucky_ball_extraa);
     		lucky_ball_number_extra = toint(input_lucky_ball_extraa);
			 }
  			while (!digit_check(input_lucky_ball_extraa)||lucky_ball_number_extra>14||lucky_ball_number_extra<1);
    		
    		system ("cls");

			//Convert char inputs to integer
    		lucky_ball_number[0] = toint(input_lucky_ball_1);
    		lucky_ball_number[1] = toint(input_lucky_ball_2);
    		lucky_ball_number[2] = toint(input_lucky_ball_3);
    		lucky_ball_number[3] = toint(input_lucky_ball_4);
    		lucky_ball_number[4] = toint(input_lucky_ball_5);
    		lucky_ball_number_extra = toint(input_lucky_ball_extraa);
    		    		
    		//True check
    		for(point_counter_1=0; point_counter_1 < 5; point_counter_1++){
    			int found = 0;
            	for(point_counter_2=0; point_counter_2 < 5; point_counter_2++){ 
                  	if(lucky_ball_number[point_counter_2] == lucky_ball[point_counter_1]){
                  		if(!found){
						  true_control++;
                          found = 1;
                   		 }
                    		break;
                	}
           		}
           	}
           	
			if(lucky_ball_number_extra == extra){//Special number
    			extra_true_control = 1;
			}
			else{
				extra_true_control = 0;
			}
			
			if(6>true_control >= 1){
				
				if(true_control>=3){
					lucky_ball_point = true_control * (true_control * (true_control * (true_control * (43 * true_control -420) + 1605) - 2580)+ 1472)/120; 
				}
				else if(true_control == 1 || true_control==2){
					lucky_ball_point = 0;
				}
				
				if(extra_true_control==1){
					
					if(true_control==1){
						lucky_ball_point=2;
					}
					
					else if(true_control==2){
						lucky_ball_point=4;
					}
					
					else if(!(true_control==1 && true_control==2)){
						lucky_ball_point=lucky_ball_point*2;
					}
					
				}
				
				points = points+lucky_ball_point;
			}
			else
			{
				lucky_ball_point = 0;
			}
			
			printf("\t\t\t\t\tLucky Numbers:  ");
			orderlts(lucky_ball,5);//Go to order function and sorted numbers are printed in this function
			printf(" %d \n",extra);
			printf("\n");
			printf("\t\t\t\t\tYour Numbers:   ");
			orderlts(lucky_ball_number,5);//Go to order function and sorted numbers are printed in this function
			printf(" %d",lucky_ball_number_extra);
			printf("\n");
			printf("\t\t\t\t\tTrue: %d + %d ",true_control,extra_true_control);
			printf("\n\n");
			printf("\t\t\t\t\t%d points earned! \n\n",lucky_ball_point);
			lucky_ball_point=0;
			true_control=0;
			extra_true_control = 0;
			
			flag2:
			do{
   			printf("\t\t\t\t\t1.Try Again\n\t\t\t\t\t2.Main Menu\n\t\t\t\t\t3.Save\n\t\t\t\t\t4.Exit\n");
   			printf("\t\t\t\t\t");
    		scanf("%s",&choice2_c);
			}
  			while (!digit_check(choice2_c));
			choice2=toint(choice2_c);
			while(choice2>4||choice2<1){
			printf("\t\t\t\t\tPlease enter a valid number!\n\n");
			goto flag2;
			}
			
			switch(choice2){
				
				case 1:
					
					system("cls");
					Lucky_Ball();
					
				case 2:
					
					system("cls");
					main();
					
				case 3:
					
					Record(points);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Successfully saved!\n\n");
					Sleep(2000);
					system("cls");
					main();
					
				case 4:
					
					exit(0);
					
			}
			
}

int Super_Lotto(){
		
			srand(time(NULL));
			
			for (random_counter_1 = 0; random_counter_1 < 6; random_counter_1++)
  			{
   				do
  				{
      			random = (rand() % 54) + 1;
     			unique = true;
      			for (random_counter_2 = 0; random_counter_2 < random_counter_1; random_counter_2++)
       			if (super_lotto[random_counter_2] == random) unique = false;
   				} 
				while (!unique);
   				super_lotto[random_counter_1] = random;
			}	
			
   			do{
       		printf("\t\t\t\t\tInput a number 1 [1-54]: ");
     		scanf("%s",input_super_lotto_1);
     		super_lotto_number[0] = toint(input_super_lotto_1);
			 }
  			while (!digit_check(input_super_lotto_1)||super_lotto_number[0]>54||super_lotto_number[0]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 2 [1-54]: ");
     		scanf("%s",input_super_lotto_2);
     		super_lotto_number[1] = toint(input_super_lotto_2);
			 }
  			while (!digit_check(input_super_lotto_2)||super_lotto_number[1]>54||super_lotto_number[1]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 3 [1-54]: ");
     		scanf("%s",input_super_lotto_3);
     		super_lotto_number[2] = toint(input_super_lotto_3);
			 }
  			while (!digit_check(input_super_lotto_3)||super_lotto_number[2]>54||super_lotto_number[2]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 4 [1-54]: ");
     		scanf("%s",input_super_lotto_4);
     		super_lotto_number[3] = toint(input_super_lotto_4);
			 }
  			while (!digit_check(input_super_lotto_4)||super_lotto_number[3]>54||super_lotto_number[3]<1);
  			
   			do{
       		printf("\t\t\t\t\tInput a number 5 [1-54]: ");
     		scanf("%s",input_super_lotto_5);
     		super_lotto_number[4] = toint(input_super_lotto_5);
			 }
  			while (!digit_check(input_super_lotto_5)||super_lotto_number[4]>54||super_lotto_number[4]<1);

   			do{
       		printf("\t\t\t\t\tInput a number 6 [1-54]: ");
     		scanf("%s",input_super_lotto_6);
     		super_lotto_number[5] = toint(input_super_lotto_6);
			 }
  			while (!digit_check(input_super_lotto_6)||super_lotto_number[5]>54||super_lotto_number[5]<1);
    		
    		system ("cls");

    		super_lotto_number[0] = toint(input_super_lotto_1);
    		super_lotto_number[1] = toint(input_super_lotto_2);
    		super_lotto_number[2] = toint(input_super_lotto_3);
    		super_lotto_number[3] = toint(input_super_lotto_4);
    		super_lotto_number[4] = toint(input_super_lotto_5);
    		super_lotto_number[5] = toint(input_super_lotto_6);
    		
    		for(point_counter_1=0; point_counter_1 < 6; point_counter_1++){
    			int found = 0;
            	for(point_counter_2=0; point_counter_2 < 6; point_counter_2++){ 
                  	if(super_lotto_number[point_counter_2] == super_lotto[point_counter_1]){
                  		if(!found){
						  true_control++;
                          found = 1;
                   		 }
                    		break;
                	}
           		}
           	}	
			
			if(true_control >= 3){
				
				multiplier=true_control-2 ;
				super_lotto_point = 16 * pow(2,multiplier);
				points = points+super_lotto_point;
			}
			else{
				super_lotto_point = 0;

			}
			
			printf("\t\t\t\t\tLucky Numbers:  ");
			orderstl(super_lotto,6);
			printf("\n");
			printf("\t\t\t\t\tYour Numbers:   ");
			orderstl(super_lotto_number,6);
			printf("\n");
			printf("\t\t\t\t\tTrue: %d  ",true_control);
			printf("\n\n");
			printf("\t\t\t\t\t%d points earned! \n\n",super_lotto_point);
			super_lotto_point=0;
			true_control=0;
    				
			flag3:
			do{
   			printf("\t\t\t\t\t1.Try Again\n\t\t\t\t\t2.Main Menu\n\t\t\t\t\t3.Save\n\t\t\t\t\t4.Exit\n");
   			printf("\t\t\t\t\t");
    		scanf("%s",&choice2_c);
			}
  			while (!digit_check(choice2_c));
			choice2=toint(choice2_c);
			while(choice2>4||choice2<1){
			printf("\t\t\t\t\tPlease enter a valid number!\n\n");
			goto flag3;
			}
			
			switch(choice2){
				
				case 1:
					
					system("cls");
					Super_Lotto();
					
				case 2:
					
					system("cls");
					main();
					
				case 3:
					
					Record(points);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Successfully saved!\n\n");
					Sleep(2000);
					system("cls");
					main();
					
				case 4:
					
					exit(0);
			}
}

int toint(char str[])//Since the number values we get are "char", this is the part that is converted to "int".
{
    int len = strlen(str);
    int num = 0;
 
    for (toint_counter = 0; toint_counter < len; toint_counter++)
    {
        num = num + ((str[len - (toint_counter + 1)] - '0') * pow(10, toint_counter));
    }
 
   return num;
}

int orderstl(int array_stl[],int  user_counter){//This is the part where we sort the numbers from smallest to largest.
      
      for(orderstl_counter_1=0; orderstl_counter_1 <  user_counter; orderstl_counter_1++){
            for(orderstl_counter_2=0; orderstl_counter_2 <  user_counter; orderstl_counter_2++){
                  if(array_stl[orderstl_counter_1]<=array_stl[orderstl_counter_2]){
                        stl_variable=array_stl[orderstl_counter_1];  
                        array_stl[orderstl_counter_1]=array_stl[orderstl_counter_2];
                        array_stl[orderstl_counter_2]=stl_variable;
                        }
                  }
            }
            
      for(orderstl_counter_1 = 0; orderstl_counter_1 < user_counter; orderstl_counter_1++){
        printf("%d ",array_stl[orderstl_counter_1]);
      	}
}

int orderlts(int array_lts[],int user_counter){//This is the part where we sort the numbers from largest to smallest.
      
      for(orderlts_counter_1=0; orderlts_counter_1 < user_counter; orderlts_counter_1++){
            for(orderlts_counter_2=0; orderlts_counter_2 < user_counter; orderlts_counter_2++){
                  if(array_lts[orderlts_counter_2] <= array_lts[orderlts_counter_1]){
                        lts_variable=array_lts[orderlts_counter_1];  
                        array_lts[orderlts_counter_1]=array_lts[orderlts_counter_2];
                        array_lts[orderlts_counter_2]=lts_variable;
                        }
                  }
            }

      for(orderlts_counter_1 = 0; orderlts_counter_1 < user_counter; orderlts_counter_1++){
        printf("%d ",array_lts[orderlts_counter_1]);
      }
      
}

int Record(int score){//This part
	
	printf("\t\t\t\t\tEnter your name: ");
	scanf("%s",&name);//Get name from user
	FILE* file = fopen("scores.txt", "a");//Open scores.txt with "a" parameter
	fprintf(file, "%s %d\n", name, score);//Write name and score in file
	fclose(file);
   	
}

int ViewRecord(){
	
	FILE *file;
	file = fopen("scores.txt", "r"); // The "r" parameter opens the file in read mode
	//Start reading data from file
	while (fscanf(file, "%s %d", name, &score) != EOF) {
	printf("\t\t\t\t\tUsername: %s", name);
	printf("\t\t Score: %d\n", score);
	}	
	// Close the file
	fclose(file);
    
}

int settings(){
	
	flag4:
			do{
   			printf("\t\t\t\t\t1.Black\n\t\t\t\t\t2.White\n\t\t\t\t\t3.Red\n\t\t\t\t\t4.Blue\n\t\t\t\t\t5.Yellow\n\t\t\t\t\t6.Light Yellow\n\t\t\t\t\t7.Pink\n\t\t\t\t\t8.Green\n\t\t\t\t\t9.Aqua\n");
   			printf("\t\t\t\t\t");
    		scanf("%s",&mode_c);
			}
  			while (!digit_check(mode_c));
			mode=toint(mode_c);
			while(mode>9||mode<1){
			printf("\t\t\t\t\tPlease enter a valid number!\n\n");
			goto flag4;
			}
			
			switch(mode){
				
				case 1:
					
					system("color 0F");//Black
					system("cls");
					main();
					
				case 2:
					
					system("color F0");//White
					system("cls");
					main();
					
				case 3:
					
					system("color 40");//Red
					system("cls");
					main();
					
				case 4:
					
					system("color 9F");//Blue
					system("cls");
					main();
					
				case 5:
					
					system("color 60");//Yellow
					system("cls");
					main();
					
				case 6:
					
					system("color e0");//Light yellow
					system("cls");
					main();
						
				case 7:
					
					system("color D0");//Pink
					system("cls");
					main();
					
				case 8:
					
					system("color 2F");//Green
					system("cls");
					main();
					
				case 9:
					
					system("color b0");//Aqua
					system("cls");
					main();	
			}
}

int DeleteSaves(){
	
	system("cls");
	FILE* file = fopen("scores.txt", "w");//Open scores.txt. "w" opens file in overwrite mode
	fprintf(file, "");//Write nothing in file
	fclose(file);//Close the file
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Successfully Deleted!\n\n");//Print "Successfully Deleted!" 
	Sleep(2000);//2 second delay
	system("cls");//Clear screen
	main();//Go to main function
}

