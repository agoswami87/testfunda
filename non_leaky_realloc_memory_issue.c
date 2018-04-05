#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define StrToReplace "Anjan Goswami Engg" //to become Anjan kanu lal Engg
void replacePatternAnywhere(char *origBuff, char *searchPattern, char *replaceWith);

int main(){
	char *str=NULL;
	char replaceWith[20]="kanu lal";
	char searchPattern[20]="Goswami";
	str=malloc(sizeof(char)*(strlen(StrToReplace)+1));
	memset(str,0,sizeof(char)*(strlen(StrToReplace)+1));
	memcpy(str,StrToReplace,strlen(StrToReplace)+1);
	printf("Before replace: %p %s\n",str,str);
	replacePatternAnywhere(str,searchPattern,replaceWith);
	printf("Address after replace: %p %s\n",str,str);
	free(str);
	return 0;
}
void replacePatternAnywhere(char *origBuff, char *searchPattern, char *replaceWith){
	char *pattrnStart =strstr(origBuff, searchPattern);
	if(pattrnStart!=NULL){//means found
		printf("Keeping copies %p\n",origBuff);

		char *pattrnEnd= pattrnStart+strlen(searchPattern);
		char *aftrPattrn = malloc(sizeof(char) * (strlen(origBuff) - (pattrnEnd-origBuff)+1)); //i.e. from pattrnEnd upto end
		memcpy(aftrPattrn, pattrnEnd , strlen(origBuff) - (pattrnEnd - origBuff)+1); //All content copied after pattern

                printf("Altering memory\n");

		origBuff = realloc(origBuff, sizeof(char) * (strlen(origBuff) + strlen(replaceWith) - strlen(searchPattern) + 1 ));
		if(origBuff!=NULL){ //i.e. memory allocated
			pattrnStart =strstr(origBuff, searchPattern); //find again due to realloc

			memcpy(pattrnStart,replaceWith,strlen(replaceWith)); //payload copied
			memcpy(pattrnStart+strlen(replaceWith) , aftrPattrn ,strlen(aftrPattrn));
			printf("After Replace: %p %s\n",origBuff,origBuff);

		}
		free(aftrPattrn);
	}
}
