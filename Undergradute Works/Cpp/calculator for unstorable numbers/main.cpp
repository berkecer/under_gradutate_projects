#include "be_header.h"
using namespace std;
int main(int argc, char* args[])
{
    //-------------- FILE READER --------------
    string STRING;
    string input_lines[150];
    ifstream infile;
    infile.open(args[1]);
    FILE* outfile = fopen(args[2],"w");
    int a=0;
    int indexer = 0;
    string previousLine="";
    while(a<1) { // to get all the lines
        getline(infile,STRING); // Saves the line in STRING.
        if (STRING != previousLine){
            previousLine=STRING;
            input_lines[indexer]=STRING;
            indexer++;
            // Prints our STRING.
        }else{
            a=2;
        }
    }
    infile.close();

    //-------------- END OF FILE READER --------------

    // ------------- FILE PARSER ----------------------
    int i;
    for(i=0;i<indexer;i++){ // for each line
        //"---------------------------- START -----------------------------------"
        BE_Stack<Line_Piece> Numbers;
        BE_Stack<Line_Piece> Operands;

        //------------------ PARSING ------------------
        string s = input_lines[i];
        string delimiter = " ";
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos){
            token = s.substr(0, pos);
            if(token.length()==1){
                if(token=="+"||token=="-"||token=="*"||token=="/"||token=="^"){
                    //"token is operand"
                    Line_Piece operand_sign;
                    operand_sign.operandSign[0]=token[0];
                    Operands.Push_NewElement(operand_sign);
                }else{
                    //token is 1 digit positive number
                    Line_Piece big_number;
                    char* temp = (char*)malloc(sizeof(char));
                    temp[0] = token[0];
                    big_number.numbers[0] = atoi(temp);
                    big_number.numbers_count=1;
                    Numbers.Push_NewElement(big_number);
                    free(temp);
                }
            }else if(token.length()>1){
                //long numbers here
                if(token[0]=='-'){
                    //negative long number
                    //keep every digit negative
                    Line_Piece big_number;
                    int number_lenght;
                    number_lenght =token.length();
                    int i;
                    for(i=1;i<number_lenght;i++){
                        char* temp = (char*)malloc(sizeof(char));
                        temp[0] = token[i];
                        big_number.numbers[i-1] = 0 - atoi(temp);
                        free(temp);

                    }
                    big_number.numbers_count=number_lenght-1;
                    Numbers.Push_NewElement(big_number);
                }else{
                    //positive long number
                    Line_Piece big_number;
                    int number_lenght;
                    number_lenght =token.length();
                    int i;
                    for(i=0;i<number_lenght;i++){
                        char* temp = (char*)malloc(sizeof(char));
                        temp[0] = token[i];
                        big_number.numbers[i] = atoi(temp);
                        free(temp);
                    }
                    big_number.numbers_count=number_lenght;
                    Numbers.Push_NewElement(big_number);
                }
            }
            s.erase(0, pos + delimiter.length());
        }
        // FOR THE LAST PIECE
        if(s.length()==1){
                if(s=="+"||s=="-"||s=="*"||s=="/"||s=="^"){
                    Line_Piece operand_sign;
                    operand_sign.operandSign[0]=s[0];
                    Operands.Push_NewElement(operand_sign);
                }else{
                    Line_Piece big_number;
                    char* temp = (char*)malloc(sizeof(char));
                    temp[0] = s[0];
                    big_number.numbers[0] = atoi(temp);
                    free(temp);
                    big_number.numbers_count=1;
                    Numbers.Push_NewElement(big_number);
                }
            }else if(s.length()>1){
                if(s[0]=='-'){
                    Line_Piece big_number;
                    int number_lenght;
                    number_lenght =s.length();
                    int i;
                    for(i=1;i<number_lenght;i++){
                        char* temp = (char*)malloc(sizeof(char));
                        temp[0] = s[i];
                        big_number.numbers[i-1] = 0 - atoi(temp);
                        free(temp);
                    }
                    big_number.numbers_count=number_lenght-1;
                    Numbers.Push_NewElement(big_number);
                }else{
                    Line_Piece big_number;
                    int number_lenght;
                    number_lenght =s.length();
                    int i;
                    for(i=0;i<number_lenght;i++){
                        char* temp = (char*)malloc(sizeof(char));
                        temp[0] = s[i];
                        big_number.numbers[i] = atoi(temp);
                        free(temp);
                    }
                    big_number.numbers_count=number_lenght;
                    Numbers.Push_NewElement(big_number);
                }

            }

        int IsThereNanValue = 0;
        int forLoop = Operands.ElementCount;
        int ForLoopVar;
        for(ForLoopVar=0;ForLoopVar<forLoop;ForLoopVar++){
            // Take the operator from stack
            Line_Piece OperandToExecute = Operands.Top_GetElement();
            Operands.Pop_LastElement();
            // Take Right Number(1) from Number Stack
            Line_Piece RightNumber = Numbers.Top_GetElement();
            Numbers.Pop_LastElement();
            // Take Left Number(2) from Number Stack
            Line_Piece LeftNumber = Numbers.Top_GetElement();
            Numbers.Pop_LastElement();

            //Decide Which Operation will be Executed
            if(OperandToExecute.operandSign[0]=='+'){
                // check for negative numbers
                int NegativeNumberCount = 0;
                int IsLeftNumberNegative = 0;
                int IsRightNumberNegative = 0;
                if(LeftNumber.numbers[0]<0){
                    IsLeftNumberNegative=1;
                    NegativeNumberCount++;
                }
                if(RightNumber.numbers[0]<0){
                    NegativeNumberCount++;
                    IsRightNumberNegative = 1;
                }
                Line_Piece ResultOfAddition;
                if(NegativeNumberCount==1){
                        // Send to Subtraction
                        if(IsLeftNumberNegative == 1){
                            // -100 + 3
                            // -3 + 100
                            if(LeftNumber.numbers_count< RightNumber.numbers_count){
                                ResultOfAddition = RightNumber - LeftNumber.Minus();
                            }else{
                                ResultOfAddition = LeftNumber.Minus() - RightNumber;
                                ResultOfAddition = ResultOfAddition.Minus();
                            }
                        }else if(IsRightNumberNegative == 1){
                            // 100 + -3
                            // 3 + -100
                            if(LeftNumber.numbers_count<RightNumber.numbers_count){
                                ResultOfAddition = RightNumber.Minus() - LeftNumber;
                                ResultOfAddition = ResultOfAddition.Minus();
                            }else{
                                ResultOfAddition = LeftNumber - RightNumber.Minus();
                            }

                        }

                }else if(NegativeNumberCount==2){
                    LeftNumber=LeftNumber.Minus();
                    RightNumber=RightNumber.Minus();
                    ResultOfAddition= LeftNumber + RightNumber;
                    ResultOfAddition = ResultOfAddition.Minus();
                }else if(NegativeNumberCount==0){
                    ResultOfAddition= LeftNumber + RightNumber;
                }

                Numbers.Push_NewElement(ResultOfAddition);

            }else if(OperandToExecute.operandSign[0]=='-'){

                Line_Piece ResultOfSubtraction;
                if(LeftNumber.numbers[0]>0 && RightNumber.numbers[0]<0){
                    ResultOfSubtraction = LeftNumber + RightNumber.Minus();
                }else{
                    if(LeftNumber.numbers_count < RightNumber.numbers_count && RightNumber.numbers[0]>0){
                        ResultOfSubtraction = RightNumber - LeftNumber;
                        ResultOfSubtraction = ResultOfSubtraction.Minus();
                    }else if(LeftNumber.numbers_count > RightNumber.numbers_count && LeftNumber.numbers[0]<0){
                        ResultOfSubtraction = RightNumber - LeftNumber;
                        ResultOfSubtraction = ResultOfSubtraction.Minus();
                    }else if(LeftNumber.numbers_count > RightNumber.numbers_count && LeftNumber.numbers[0]<0 && RightNumber.numbers[0]<0){
                        ResultOfSubtraction = LeftNumber.Minus() - RightNumber.Minus();
                        ResultOfSubtraction = ResultOfSubtraction.Minus();
                    }else{
                        ResultOfSubtraction = LeftNumber - RightNumber;
                    }
                }
                Numbers.Push_NewElement(ResultOfSubtraction);

            }else if(OperandToExecute.operandSign[0]=='*'){
                // I will save result here
                Line_Piece ResultOfMultipication;
                int NegativeNumberCount = 0;
                // check number 1 for negativity
                if(LeftNumber.numbers[0]<0){
                    LeftNumber=LeftNumber.Minus();
                    NegativeNumberCount++;
                }
                // check number 2 for negativity
                if(RightNumber.numbers[0]<0){
                    RightNumber = RightNumber.Minus();
                    NegativeNumberCount++;
                }
                // At this point both numbers are positive

                if(LeftNumber.numbers_count<RightNumber.numbers_count){
                    ResultOfMultipication = RightNumber * LeftNumber;
                }else{
                    ResultOfMultipication = LeftNumber * RightNumber;
                }

                // set multipication sign for correction
                if(NegativeNumberCount==1){
                    ResultOfMultipication = ResultOfMultipication.Minus();
                }

                while(ResultOfMultipication.numbers[0]==0 && ResultOfMultipication.numbers_count>1){
                        ResultOfMultipication = ResultOfMultipication.DeleteFirstZero();
                }

                Numbers.Push_NewElement(ResultOfMultipication);

            }else if(OperandToExecute.operandSign[0]=='^'){
                Line_Piece ResultOfPower;
                if(LeftNumber.numbers[0]==0&&RightNumber.numbers[0]==0){
                    //break the operation because there is NaN value
                    IsThereNanValue++;
                    break;
                }
                else{
                    if(LeftNumber.numbers[0]==0){
                        ResultOfPower.numbers[0]=0;
                        ResultOfPower.numbers_count=1;
                    }else if(RightNumber.numbers[0]==0){
                        ResultOfPower.numbers[0]=1;
                        ResultOfPower.numbers_count=1;
                    }else if(RightNumber.numbers[0]<0){
                        //"Negative Power Entered";
                    }else if(RightNumber.numbers_count>1){
                        RightNumber.numbers[0] +=RightNumber.numbers[0]*10 + RightNumber.numbers[1];
                        RightNumber.numbers_count--;
                        ResultOfPower = LeftNumber^RightNumber;
                    }else{
                        ResultOfPower = LeftNumber^RightNumber;
                    }
                    Numbers.Push_NewElement(ResultOfPower);
                }
            }else if(OperandToExecute.operandSign[0]=='/'){

                 int NegativeNumberCount = 0;
                 // check number 1 for negativity
                 if(LeftNumber.numbers[0]<0){
                     LeftNumber=LeftNumber.Minus();
                     NegativeNumberCount++;
                 }
                 // check number 2 for negativity
                 if(RightNumber.numbers[0]<0){
                     RightNumber = RightNumber.Minus();
                     NegativeNumberCount++;
                 }
                 // At this point both numbers are positive


                 Line_Piece ResultOfDivision;
                 if(RightNumber.numbers[0]==0){
                    //break the operation because there is NaN value
                    IsThereNanValue++;
                    break;
                 }else if(LeftNumber.numbers[0]==0){
                    ResultOfDivision.numbers[0] = 0;
                    ResultOfDivision.numbers_count=1;
                 }else if(LeftNumber.numbers_count<RightNumber.numbers_count){
                    ResultOfDivision.numbers[0]=0;
                    ResultOfDivision.numbers_count=1;
                 }else{
                    ResultOfDivision = LeftNumber/RightNumber;                 }

                 if(NegativeNumberCount==1){
                    ResultOfDivision= ResultOfDivision.Minus();
                 }
                 Numbers.Push_NewElement(ResultOfDivision);
            }
        }



        /*"--------------------------- END---------------------------------------"*/


        if(IsThereNanValue==0){
            Line_Piece PrintTheResult = Numbers.Top_GetElement();
            if(PrintTheResult.numbers[0]<0){
                fprintf(outfile,"-");
                PrintTheResult = PrintTheResult.Minus();
            }
            PrintTheResult.PrintNumber(outfile);
        }else{
            fprintf(outfile,"NaN\n");
        }



    }
    // ------------------------ END OF FILE PARSE --------------------------
    return 0;
}
