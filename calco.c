#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//need to modify
float out_num(float nums[],char opr[],int k){
    char opt[4] = {'/', '*', '-', '+'};
    int opIndex[4] = {0};
    int opCount[4] = {0};

    for (int j = 0; j < k; j++) {
        for (int i = 0; i < 4; i++) {
            if (opr[j] == opt[i]) {
                opCount[i]++;
                opIndex[i] = j;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < opCount[i]; j++) {
            int index = opIndex[i] - j;
            if (opt[i] == '/') {
                nums[index] = nums[index] / nums[index + 1];
                nums[index + 1] = 0;
            } else if (opt[i] == '*') {
                nums[index] = nums[index] * nums[index + 1];
                nums[index + 1] = 0;
            } else if (opt[i] == '-') {
                nums[index] = nums[index] - nums[index + 1];
                nums[index + 1] = 0;
            } else if (opt[i] == '+') {
                nums[index] = nums[index] + nums[index + 1];
                nums[index + 1] = 0;
            }
        }
    }

    return nums[0];
}

void equle(char *str,float *r){
	char opr[100];//may change the number
	float nums[100];//may change the number
	//maybe shuold use dynmic array or linked list for nums
	char strn[100] = "\0";//may change the number
	int k = 0;
	for(int i = 0;i<strlen(str);i++){
		if(str[i]<=47){
			opr[k] = str[i];
			k++;
			strn[0] = '\0';
		}
		else{
			sprintf(strn+strlen(strn),"%c",str[i]);
			nums[k] = atof(strn);
			//printf("%f , %s\n",nums[k],strn);
		}
	}
	*r = out_num(nums,opr,k);
}
