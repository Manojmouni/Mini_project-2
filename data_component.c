
/* ----------------------------  Function Description   ---------------------------------- */
/***
 * Name of the module:   database.c 
 -----------------------------------------
 * Name of the Function:  data_component function
 *  
 * Date of creation:      16/11/2022
 *
 * Author of module:     Aishwarya D
 *
 * Description of module: 
 *                      In main menu,when data_component is called, the data in the excel sheet should be accessed.      
 
 * Different functions supported in the module: database_modify,
 						database_add,
					        database_delete.                                           
                                                
 * Global variables accessed or modified by the module: Access Structure pointer, TS_India_Employee_DB

 * Revision/Modification History:25/11/2022
 ***/


#include"header.h"

void data_component(employee_database **hptr)
{
	int i=0,j=0,flag = 0,num=0;//declare the i ,j ,flag ,num with 0
	char test_data[200],ch;//declare the char array
	employee_database *temp = 0,*new = 0;//declare the structure pointer
	FILE *fp;//declare the file pointer
	fp = fopen("TS_India_Employee_DB.csv","r+");//open the file in read write mode
	if(fp == NULL)// checking the file is open or not
	{
		printf("FIle is not there\n");
		return ;
	}
	fseek(fp,0,SEEK_SET); // Moving the file pointer to starting of the file
	while((ch=fgetc(fp))!=EOF)//reading the excel file data byte by byte till the end of the file
	{

		test_data[i++]=ch;//storing the data in a char buffer
		new=(employee_database *)malloc(sizeof(employee_database));//dynamic memory allocation for structure.
		while((ch=fgetc(fp))!='\n')//reading the data till new line
		{
			if(ch==',')//checking the comma for separating the data
			{
				test_data[i++]='\0';
				i=0;
				flag++;
				if(flag==1)//Employee ID separation condition
				{
					for(j=0;test_data[j];j++)
						test_data[j]=test_data[j+2];
					strcpy(new->emp_id,test_data);//copy the buffer data to struct
					memset(test_data,'\0',sizeof(test_data));//clear the buffer
				}
				if(flag==2)//Name separation condition
				{
					strcpy(new->name,test_data);
					memset(test_data,'\0',sizeof(test_data));
				}
				if(flag==3)//Gender separation condition
				{
					strcpy(new->gender,test_data);
					memset(test_data,'\0',sizeof(test_data));
				}
				if(flag==4)//Email ID separation condition
				{
					strcpy(new->email_id,test_data);
					memset(test_data,'\0',sizeof(test_data));
				}
				if(flag==5)//band separation condition
				{
					strcpy(new->band,test_data);
					memset(test_data,'\0',sizeof(test_data));
				}
				if(flag==6)//DOJ separation condition
				{
					strcpy(new->doj,test_data);
					memset(test_data,'\0',sizeof(test_data));
				}
				if(flag==7)//Status separation condition
				{
					strcpy(new->status,test_data);
					memset(test_data,'\0',sizeof(test_data));
				}
				if(flag==8)//Mobile No. separation condition
				{
					strcpy(new->contact_no,test_data);
					memset(test_data,'\0',sizeof(test_data));
				}
				if(flag==9)//Reporting Manager separation condition
				{
					strcpy(new->reporting_manager,test_data);
					memset(test_data,'\0',sizeof(test_data));
				}
				if(flag==10)//Reportees separation condition
				{
					strcpy(new->reportees,test_data);
					memset(test_data,'\0',sizeof(test_data));
				}
				if(flag==11)//Tech_area separation condition
				{
					strcpy(new->tech_area,test_data);
					memset(test_data,'\0',sizeof(test_data));
				}
				if(flag==12)//Project info separation condition
				{
					strcpy(new->project_info,test_data);
					memset(test_data,'\0',sizeof(test_data));
					flag = 0;
				}

			}
			else
			{
				test_data[i++]=ch;//Storing the data in buffer
			}
		}
		if(num>0)
		{
			if(*hptr == NULL)// check if head is NULL
			{
				new->link = *hptr;
				*hptr = new;
			}
			else
			{
				temp = *hptr;
				while(temp->link != NULL)
					temp = temp->link;
				new->link = temp->link;
				temp->link = new;
			}
		}
		if(ch == '\n')
			num++;
	}
}


void database_add(employee_database *emp)//function for add the data from the xl file
{
	FILE *fp;//declare the file pointer
	fp = fopen("TS_India_Employee_DB.csv","r+");//open the file in read write mode
	if(fp == NULL)// checking the file is open or not
	{
		printf("FIle is not there\n");
		return ;
	}
	fseek(fp,0,SEEK_END);// Moving the file pointer to starting of the file
	fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,\\n\n",emp->emp_id,emp->name,emp->gender,emp->email_id,emp->band,emp->doj,emp->status,emp->contact_no,emp->reporting_manager,emp->reportees,emp->tech_area,emp->project_info);//writing the all data in the xl file
	rewind(fp);//sets the file pointer at the beginning of the stream
	fclose(fp);//closing the file.
}


void database_modify(employee_database **head)//function for modify the data from the xl file
{
	FILE *fp;//declare the file pointer
	char ch,buf[180];//declare the char array
	int i=0,flag=0;//declare the i & flag with 0
	employee_database *new=(*head);//initialize the new to head
	fp= fopen("TS_India_Employee_DB.csv","r+");//open the file in read write mode

	if(fp == NULL)// checking the file is open or not
	{
		printf("file can not be open for some reason:\n");
		return;
	}
	while((ch=getc(fp))!=EOF)//read the data byte from the excel file
	{
		if(ch == '\n')//checking new line
			i=0;
		buf[i++]=ch;//storing the data in char array
		if(flag == 1)//checking the flag
		{

			fseek(fp,-1,SEEK_CUR);// Moving the file pointer to current of the file
			fprintf(fp,",%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",new->name,new->gender,new->email_id,new->band,new->doj,new->status,new->contact_no,new->reporting_manager,new->reportees,new->tech_area,new->project_info);//writing the data in the xl file after finding the id
			flag=0;//assign zero to flag
			memset(buf,'\0',sizeof(buf));//clear the buffer
		}
		if(strstr(buf,new->emp_id))//searching the emp_id from the char buffer
			flag=1;//enable the flag
		if(i==179)//checking the i value and initilize with zero for avoiding the buffer over flow and segmentation fault
			i=0;

	}

	fclose(fp);//closing the file.
}


void database_delete(employee_database *data)
{
	FILE *fp;//declare the file pointer
	char ch,buf[180],status_resign[10]="Resigned";//declare the char array
	int i=0,flag=0;//declare the i & flag with 0
	employee_database *new=data;
	fp= fopen("TS_India_Employee_DB.csv","r+");//open the file in read write mode

	if(fp == NULL)// checking the file is open or not
	{
		printf("file can not be open for some reason:\n");
		return;
	}

	strcpy(new->status,status_resign);

	while((ch=getc(fp))!=EOF)//read the data byte from the excel file
	{
		if(ch == '\n')//checking new line
			i=0;
		buf[i++]=ch;//storing the data in char array
		if(flag == 1)//checking the flag
		{

			fseek(fp,-1,SEEK_CUR);
			fprintf(fp,",%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",new->name,new->gender,new->email_id,new->band,new->doj,new->status,new->contact_no,new->reporting_manager,new->reportees,new->tech_area,new->project_info);//writing the data in the xl file after finding the id
			flag=0;//assign zero to flag
			memset(buf,'\0',sizeof(buf));//clear the buffer
		}
		if(strstr(buf,new->emp_id))//searching the emp_id from the char buffer
			flag=1;//enable the flag
		if(i==179)//checking the i value and initilize with zero for avoiding the buffer over flow and segmentation fault
			i=0;

	}

	fclose(fp);//closing the file.
}



