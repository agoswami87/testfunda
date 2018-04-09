#include<stdio.h>
struct cwmp__ParameterValueStruct
{
        char *Name;     /* required element of type xsd:string */
        int __type;     /* any type of element <Value> (defined below) */
        void *Value;    /* transient */
};

struct ParameterValueList
{
        struct cwmp__ParameterValueStruct **__ptrParameterValueStruct;
        int __size;
};

typedef struct  {
                struct ParameterValueList *parameterList;
                unsigned int fault_code;
}GetStatus;


int main(){
  char *name,*name2=NULL;
  void *value,*value2=NULL;
  int i;
  name = (char *)malloc(10);
  value=(void *)malloc(10);

  if(name && value){
	  memcpy(name,(char *)"Anjan",sizeof("Anjan"));
	  memcpy(value,(char *)"Goswami",sizeof("Goswami"));
  }

  struct cwmp__ParameterValueStruct *arr = (struct cwmp__ParameterValueStruct *)malloc(sizeof(struct cwmp__ParameterValueStruct));
  arr->Name=name;
  arr->Value=value;
  arr->__type=1;

  //1st data block filled

  struct cwmp__ParameterValueStruct ** tst = (struct cwmp__ParameterValueStruct **)malloc(0*sizeof(struct cwmp__ParameterValueStruct *));
  tst=realloc(tst,1*sizeof(struct cwmp__ParameterValueStruct *));
  tst[0]=arr;

  tst=realloc(tst,2*sizeof(struct cwmp__ParameterValueStruct *));
  struct cwmp__ParameterValueStruct *arr2 = (struct cwmp__ParameterValueStruct *)malloc(sizeof(struct cwmp__ParameterValueStruct));
  name2 = (char *)malloc(10);
  value2=(void *)malloc(10);
  if(name2 && value2){
	  memcpy(name2,(char *)"Soo",sizeof("Chandra"));
	  memcpy(value2,(char *)"Chandra",sizeof("Chandra"));
  }

  arr2->Name=name2;
  arr2->Value=value2;
  arr2->__type=2;
  tst[1]=arr2;

  for(i=0;i<2;i++){
	  printf("Name %s value %s\n",tst[i]->Name,tst[i]->Value);
	free(tst[i]->Name);
	free(tst[i]->Value);
  }
 free(arr2);
 free(arr);
 free(tst); 


}
