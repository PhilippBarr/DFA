#include <stdio.h>
#include <math.h>

void print(int *a,int length)
{
    int i=0;
    for(i=0;i<length;i++)
    {
        printf("\n PRINT %d \n",a[i]);
    }
}

//creates an array
int *makeArray(int n)
{
	int *array;
	array = (int *) malloc(n * sizeof(int));    //allocating n positions in the table
	return array;
}

//input values from user
int *readInput(int *inputLength)
{
     printf("\nEnter numbers: ");
    int temp;
    char ch;
    int counter=0;
    int *a;
    a=makeArray(500);

    while(2 == scanf("%d%c", &temp, &ch)){
        a[counter]=temp;
        counter++;
        if(ch == '\n')
            break;

    }
    *inputLength=counter;
    return a;
}

//takes the size of a line and counts how many real integers there are outside of " "
int findRealInt(int a)
{
    /*
        It basically takes out the spaces and calculates the actual size of the integers that are in the program
        the calculation was done with if because of the shorter execution time presented by this technique.
        we reached up to the number 9 due to that the maximum number of symbols that can be used
        is 9. Otherwise we would use iteration method.
     */
    if(a==1)
        return 1;
    if(a==3)
        return 2;
    if(a==5)
        return 3;
    if(a==7)
        return 4;
    if(a==9)
        return 5;
    if(a==11)
        return 6;
    if(a==13)
        return 7;
    if(a==15);
        return 8;
    if(a==17)
        return 9;
}

//returns an array of the actual number of integers present in each line (without spaces " ")
int *returnRealIntsNumberOnLine(int *array,int length)
{
    int *pinakas;
    int i;
    pinakas=makeArray(length);
    for(i=0;i<length;i++)
    {
        pinakas[i]=findRealInt(array[i]);
        //printf("\nARRAY [i] = %d",pinakas[i]);
    }
    return pinakas;

}

//we read the integers from the file.
int *read_ints (int *length)
{
  FILE* file = fopen ("dfa.txt", "r");
  int i = 0;
  int arrayLength=0;
  int *array;
  array=makeArray(1);

  fscanf (file, "%d", &i);
  array==makeArray(i+2*9*9);
  while (!feof (file))
    {
      //printf ("%d ", i);
      array[arrayLength]=i;
      arrayLength++;
      fscanf (file, "%d", &i);
    }
    array[arrayLength++]=i;
  fclose (file);

  *length=arrayLength;
  return array;
}

int *find_linesAndLengthOfLine(int *fileLines)
{
    FILE *fp = fopen ( "dfa.txt", "r");
    char line[1024];
    int lineCounter=0;  //counts how many lines the file has
    int counter2=0;
    char ch = getc ( fp );
    int index = 0;
    int *plithosLekseonAnaGrammi;   //counts the number of words in each line
    plithosLekseonAnaGrammi=makeArray(200);
    int i=0;

    while ( ch != EOF ) {   //traverses the file word by word

        if ( ch != '\n'){   //if this word is not a new line
            line[index++] = ch;

            counter2++; //this counter shows how many things are in each line
            plithosLekseonAnaGrammi[i]=counter2;
            //printf("\n%d",counter2);

        }else { //if we are on new line
            lineCounter++;  //we increment the counter that shows how many lines there are
            counter2=0; //we reset the counter that shows how many words each line has
            i++;


            line[index] = '\0';
            index = 0;

            //printf ( "%s\n", line );
        }
        ch = getc ( fp );

    }


    fclose ( fp );
    lineCounter++;
    int j;
    *fileLines=lineCounter;
    return plithosLekseonAnaGrammi;

}

//we find the symbols present in the file on its 2nd line
int *findSymbols(int *ints,int *realInts,int *symbolsLength)
{
    int i;
    int *returnArray;
    returnArray=makeArray(realInts[1]); //we make a table as large as the integers that are in the 2nd line of the file
    for(i=0;i<realInts[1];i++)  //the loop will be done as many times as the size of the 2nd line of the file
    {
        returnArray[i]=ints[i+1];   //we take the symbols
    }
    *symbolsLength=realInts[1];
    return returnArray;
}

int findStartingState(int *ints,int *realInts)
{
    int i,j;
    j=0;
    j=j+realInts[0]+realInts[1];    //position of the starting state
    return ints[j];

}

//returns an array of finish states and its size
int *findFinishStates(int * ints,int *realInts,int *lengthOfFinishStates)
{
    int *i;
    int j=0;
    int k;
    int finishStatesLength=realInts[3];     //the number of finish states is the integers size of the 4th line of our file
    j=j+realInts[0]+realInts[1]+1;          //position where finish states start in the table with integers
    i=makeArray(finishStatesLength+3*3);
    int counter=0;

    for(k=j;k<j+finishStatesLength;k++)
    {
        i[counter]=ints[k];
        counter++;
    }

    *lengthOfFinishStates=counter;
    return i;
}

//finds the description (5th line of file and beyond)
int *findStatesDescription(int *ints,int intsLength,int *realInts,int lines,int *DescriptionLength)
{
    int i,j,counter;
    int *a;
    int statesDescriptionLength=0;

    //print(realInts,lines);

    for(i=4;i<lines;i++)
    {
        statesDescriptionLength+=realInts[i];   //we find table size with the description of states
    }   //which is essentially the size of the numbers that exist from the 5th line to the end

    j=realInts[0]+realInts[1]+realInts[2]+realInts[3];  //size of real numbers up to the 5th line
    a=makeArray(statesDescriptionLength);
    counter=0;
    for(i=j;i<intsLength;i++)
    {
        a[counter]=ints[i];
        counter++;
    }
    *DescriptionLength=statesDescriptionLength;
    return a;

}

int *getPouEimai(int *statesDescription,int statesDescriptionLength,int *poyEimaiLength)
{
    int i;
    int counter=1;
    int *array;

    for(i=0;i<statesDescriptionLength;i+=3)
    {
        counter++;
    }
    array=makeArray(counter);
    counter=0;
    for(i=0;i<statesDescriptionLength;i+=3)
    {
        array[counter]=statesDescription[i];
        counter++;
    }
    *poyEimaiLength=counter;
    return array;

}

int *getInput(int *statesDescription,int statesDescriptionLength)
{
    int i;
    int counter=1;
    int *array;

    for(i=1;i<statesDescriptionLength;i+=3)
    {
        counter++;
    }
    array=makeArray(counter);
    counter=0;
    for(i=1;i<statesDescriptionLength;i+=3)
    {
        array[counter]=statesDescription[i];
        counter++;
    }

    return array;

}

int *getPouPaw(int *statesDescription,int statesDescriptionLength)
{
    int i;
    int counter=1;
    int *array;

    for(i=2;i<statesDescriptionLength;i+=3)
    {
        counter++;
    }
    array=makeArray(counter);
    counter=0;
    for(i=2;i<statesDescriptionLength;i+=3)
    {
        array[counter]=statesDescription[i];
        counter++;
    }

    return array;

}

int runDFA(int startState,int *finishStates,int finishStatesLength,
           int *pouEimai,int *meTiInput,int *pouPaw,int eimaiInputPawLength,int *edolesXristi,int edolesXristiLength)
{

    int i,j,k;
    int currentState=startState;    //the current state we are in is the start state
    currentState=startState;

    //printf("\ncurrent state %d \n",currentState);

    for(i=0;i<edolesXristiLength;i++)
    {
        for(j=0;j<eimaiInputPawLength;j++)
        {
            if(currentState==pouEimai[j])   //i found the state that i am from the cases array
            {
                if(edolesXristi[i]==meTiInput[j])   //i found that i am at 1 and the order i gave exists
                {
                    currentState=pouPaw[j];
                   //printf("\nCommand %d",edolesXristi[i]);
                   //printf("\ncurrent state %d \n",currentState);
                    break;
                }
            }
        }
    }
    //printf("final state %d",currentState);

    for(i=0;i<finishStatesLength;i++)
    {
        if(currentState==finishStates[i])
            return 1;
    }
    return 0;

}

void isitOrNot(int *ints,int intsLength,int *realInts,int lines)
{
    int i;

    int *edolesXristi;  //contains the commands given by the user in a table but starting from position 0
    int edolesXristiLength;//commands length

    ///ints array of the integers present in the file
    ///intsLength size of the above array
    ///eachlineLength size of real integers present on each line
    ///lines set of lines of the file (size of eachlineLength)

    int states=ints[0]; ///number of states

    int *symbols;   ///number of symbols
    int symbolsLength=realInts[1];  ///the number of different symbols is the number of integers present on the 2nd line

    int startState; ///initial state of the file

    int *finishStates;  ///final states of the file
    int finishStatesLength; ///size of array with the final states

    int  *statesDescription;
    int statesDescriptionLength;

    int *pouEimai;  //array that has the instances of where I am
    int *meTiInput; //array that has the instances of the input given
    int *pouPaw;    //array that has the instances of where I go
    int eimaiInputPawLength;    //length of the three arrays above

    symbols=findSymbols(ints,realInts,&symbolsLength);  //we found the symbols
    startState=findStartingState(ints,realInts);
    finishStates=findFinishStates(ints,realInts,&finishStatesLength);
    statesDescription=findStatesDescription(ints,intsLength,realInts,lines,&statesDescriptionLength);   //we find the description of the states and put it in a array

    ///at this point we have everything we need
    pouEimai=getPouEimai(statesDescription,statesDescriptionLength,&eimaiInputPawLength);   //one-dimensional array of the state I am
    meTiInput=getInput(statesDescription,statesDescriptionLength);  //one-dimensional array with the input
    pouPaw=getPouPaw(statesDescription,statesDescriptionLength);    //one-dimensional arra with where I'm going

    int trueFalse,ans;
    while(1)
    {
     edolesXristi=readInput(&edolesXristiLength);
     trueFalse=runDFA(startState,finishStates,finishStatesLength,pouEimai,meTiInput,pouPaw,eimaiInputPawLength,edolesXristi,edolesXristiLength);
               if(trueFalse)
                printf("\nTRUE\n");
               else
                printf("\nFALSE\n");
               printf("Do you want to do it again ? \n Yes=1\n NO=0\n");
               scanf("%d",&ans);
               if(ans==0)
           break;
    }

}

int main ( int argc, char **argv ) {
    int arrayLength;    //the size of the array of integers from the file
    int *arrayOfInts;   //the array of integers from the file

    int *arrayOfLineLength; //size of each line together with int and space, size of the table is the set of lines i.e. fileLines
    int fileLines;  //the total number of lines in the file

    int *realInts;  //the integer number on each line
    int i;
    arrayOfInts=read_ints(&arrayLength);    //integers of the file
    arrayOfLineLength=find_linesAndLengthOfLine(&fileLines);    //we get size of each line along with int, space and set of lines
    //from now on we want to find the actual ints without the space and put them in an array
    realInts=returnRealIntsNumberOnLine(arrayOfLineLength,fileLines);   //we found them
    isitOrNot(arrayOfInts,arrayLength,realInts,fileLines);


    return 0;
}
