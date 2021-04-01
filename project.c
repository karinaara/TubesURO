#include <stdio.h> //Mengimpor file stdio.h

void findPos(char *dir)
{
    int up = 0, down = 0;
    int left = 0, right = 0;
    int i;
    int x;
    int y;

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
    x = right - left
    y = up - down
    printf("Final Position of the Robot: (");
    printf("%d", (x));
    printf(",%d", (y));
    printf(")");
}

int main()
{
    char *dir;

    //Input the direction string
    printf("Enter the Direction String:  ");
    scanf("%s", &dir);

    //Function call to calculate position
    findPos(&dir);

    return 0;
}
