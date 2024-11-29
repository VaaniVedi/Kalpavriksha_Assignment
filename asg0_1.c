#include <stdio.h>
#include <limits.h>
int number(char s){
    if(s<='9'&&s>='0'){
        return 1;
    }
    return 0;
}

int space(char s){
    if(s==' '){
        return 1;
    }
    return 0;
}

int gen_num(char* s, int* i) {
    int x = 0;
    while (number(s[*i])==1) {
        x = x * 10 + (s[*i] - '0');
        (*i)++;
    }
    return x;
}

int soln(char* s) {
    int nums[10000] = {0};
    char op_sign[10000];
    int err1_code= INT_MAX, err2_code = INT_MIN;
    int num_p = 0;
    int sign_p = 0;
    int i = 0,j=0;
    while(s[j]){
        if(space(s[j])==1) j++;
        else if(number(s[j])==1) j++;
        else if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/') j++;
        else return err1_code;
    }

    while (s[i]) {
        if (space(s[i])==1) i++;
        else if (number(s[i])==1) {
            int x = gen_num(s, &i); 
            nums[num_p] = x;
            num_p++;
        } else { // if +- then move to sign array else solve the *&/
            if (s[i] == '*' || s[i] == '/') {
                char curr_operator = s[i];
                i++;
                while (space(s[i])==1)
                    i++;

                int operand_2 = gen_num(s, &i); 

                int operand_1 = nums[--num_p];

                if (curr_operator == '*') {
                    nums[num_p] = operand_1 * operand_2;
                    num_p++;
                } else {
                    if(operand_2==0){
                        printf("Error division by zero");
                        return err2_code;
                    }
                    nums[num_p] = operand_1 / operand_2;
                    num_p++;
                }
            } else {
                op_sign[sign_p] = s[i];
                i++;
                sign_p++;
            }
        }
    }

    int ans = nums[0];
    int index = 1; 
    for (int i = 0; i < sign_p; i++) {
        if (op_sign[i] == '+') {
            ans += nums[index];
        } else {
            ans -= nums[index];
        }
        index++;
    }
    return ans;
}
int main() {
    char str[10000];
    int i = 0;
    char ch;

    printf("Enter a string: ");
    
    do{
        ch=getchar();
        if(ch!='\n'){
            str[i]=ch;
            i++;
        }
    }while(ch!='\n');

    str[i] = '\0';
    int result = soln(str);

    if(str[0] == '\0'){
        printf("The input string is empty");
        return 0;
    }
    else if(result==INT_MAX){ 
        printf("Invalid character in the string"); 
        return 0;
    }

    else if(result==INT_MIN){
        return 0;
    }

    else {
        printf("Result: %d\n", result);
        return 0;
    }
}