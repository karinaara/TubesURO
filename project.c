#include <stdio.h> //Mengimpor file stdio.h
#include <stdlib.h> // Mengimpor file stdlib.h

//fungsi perpangkatan
float pangkat(int i, int l){
    if(l==0){
        return 1;                  
    }
    else
        return i * pangkat(i,l-1);  
}
//vektor jarak a kuadrat + b kuadrat
int vektor(int p, int q){
    return (pangkat(p,2) + pangkat(q,2));
}
void findPos(char *dir)
{
    int up = 0, down = 0;
    int left = 0, right = 0;
    int i;
    int x;
    int y;
    time_t t;
    int a;
    int b;

        
    for (i = 0; dir[i] != '\0' ; i++) {

        //Counts each direction
        if (dir[i] == 'U' || dir[i] == 'u')
            up++;
        else if (dir[i] == 'D' || dir[i] == 'd')
            down++;
        else if (dir[i] == 'L' || dir[i] == 'l')
            left++;
        else if (dir[i] == 'R' || dir[i] == 'r')
            right++;

          //In case of illegal character in the string
        else
        {
            printf("Position Unable to Find, Enter Correct Direction.");
            break;
        }
    }

    //Final position of robot
    x = right - left;
    y = up - down;
    printf("Final Position of the Robot: (");
    printf("%d", (x));
    printf(",%d", (y));
    printf(")");
    
    
    
    /* Intializes random number generator */

    srand((unsigned) time(&t));

    /* Print 2 random numbers from 0 to 100 */
    a = rand() % 100;
    b = rand() % 100;
    printf("\nPosisi kecoak adalah: ");
    printf("(%d,", a);
    printf("%d)", b);
   
    printf("\nJarak robot dengan kecoak");
    printf("\nJarak horizontal : %d", a-x);
    printf("\nJarak vertikal: %d", b-y);
    
}           
    // The accuracy of robot firing
void Fire(int h, int v){
    int robothealth = 100;
    int kecoakhealth = 100;
    int hit = 0;
    int miss = 0;

    if(vektor(h,v) <= pangkat(3,2)){
    hit += 1;
    kecoakhealth -= 5;
    }
    else
        miss += 1;
           
    if(hit >= 20 & kecoakhealth <= 0|| robothealth> 0){
        printf("Mission Complete\n");
    }
    else if (robothealth == 0){
        printf("Game Over\n");
    }
}
void InactivateRobot(){
    printf("Game Over\n");
    return 0;
}

int main(){
    char *dir;
    int choice;
    int x,y;
    printf("Robot Control\n");
    printf("1. Moving\n");
    printf("2. Shooting\n");
    printf("3. Inactivating\n");
    printf("\nChoose your choice: ");
    scanf("%d", &choice);
    //Input the direction string 
    switch (choice)
    {
    case 1:
        printf("Enter the Direction String:  ");
        scanf("%s", &dir);

        //Function call to calculate position
        findPos(&dir);
        break;
    case 2:
        findPos(&dir);
        //Function call to take hit and miss of shooting programm
        Fire(x,y);
        break;
    case 3:
        InactivateRobot();
    default:
        break;
    }
    return 0;
}
