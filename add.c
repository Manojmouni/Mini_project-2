
/* ----------------------------  Function Description   ---------------------------------- */
/***
 * Name of the module:   add.c 
 -----------------------------------------
 * Name of the Function:  add_data function
 *  
 * Date of creation:     11/12/2022
 *
 * Author of module:     Srujan.B
 *
 * Description of module: 
 *                      In main menu,when add_data selected head pointer and add the Employee details at the end node.

 * Different functions supported in the module: new_employee_detail, add_data_component.

 * Global variables accessed or modified by the module: Access Structure pointer, TS_India_Employee_DB

 * Revision/Modification History:15/12/2022
 ***/



#include"header.h"

void add_data(employee_database **emp)//Function for add the data from database component
{
	employee_database *temp = (employee_database *)malloc(sizeof(employee_database));//Dynamic memory allocation for structure.

	temp = new_employee_detail(temp);// Calling new_employee_detail(temp) function
	if(*emp == NULL)
	{
		temp-> link = *emp; //Assign emp to temp node link
		*emp = temp; //Assign temp address to emp
	}
	else
	{
		employee_database *last=*emp;//Initialize the last to emp 
		while(last->link != NULL)
			last = last->link; // Traversing each before last node
		temp->link = last->link; //Assign last link to temp link
		last->link = temp; //Assign temp to last link
	}
	database_add(temp);// Calling add_data_component(temp) function
}
employee_database* new_employee_detail(employee_database *temp)//Function for Enter the Employee detials
{
	char a[10];
	int i;
	printf("Enter the Employee details\n");
empid:  printf("Enter the Employee Id\t:\t");
	scanf("%s",a);
	if(strlen(a)>7)
	{
		printf("invalid id\n");
		goto empid;
	}
	else if(strlen(a)<7)
	{
		for(i=0;a[i]!='\0';i++)
		{
			if((a[i]<=48)||(a[i]>=57))
			{
			printf("invalid data\n");
				goto empid;
			}

		}
	}
	else
		strcpy(temp->emp_id,a);
empname:	printf("Enter the Employee Name \t:\t");
	scanf(" %[^\n]s",a);
	
		for(i=0;a[i]!='\0';i++)
		{
			if((a[i]<=65)||(a[i]>=122))
			{
				printf("invalid\n");
				goto empname;
			}
		}

		strcpy(temp->name,a);
	//scanf(" %[^\n]s",temp->name);
        
gender:	printf("Enter the Employee Gender \t:\t");
	char p[1];
	
	scanf("%s",p);
	if((p[0]=='M')||(p[0]=='F'))
		strcpy(temp->gender,p);
	   else
	   {
		   printf("invalid\n");
		   goto gender;
	   }
printf("Enter the Employee Email_ID\t:\t");
	scanf("%s",temp->email_id);
	printf("Enter the Employee Band \t:\t");
	scanf("%s",temp->band);
	printf("Enter the Employee Date of joining \t:\t");

	scanf("%s",temp->doj);
contno:	printf("Enter the Employee Mobile Number \t:\t");
	scanf("%s",a);
	/*if(strlen(a)>10)
	{
		printf("invalid no\n");
		goto contno;
	}*/

		for(i=0;a[i]!='\0';i++)
		{

			if((a[i]<=48)||(a[i]>=57))
			{
			printf("invalid data\n");
				goto contno;
			}
		}
		strcpy(temp->contact_no,a);
report:	printf("Enter the Reporting Manager Name \t:\t");
	scanf(" %[^\n]s",a);
		for(i=0;a[i]!='\0';i++)
		{
			if((a[i]<=65)||(a[i]>=122))
			{
			printf("invalid data\n");
				goto report;
			}
		}
	strcpy(temp->reporting_manager,a);
reportee:	printf("Enter the Reportee \t:\t");
	scanf(" %[^\n]s",a);
		for(i=0;a[i]!='\0';i++)
		{
			if((a[i]<=65)||(a[i]>=122))
			{
			printf("invalid data\n");
				goto reportee;
			}
		}
	strcpy(temp->reportees,a);
	printf("Enter the Technical Area \t:\t");
	scanf(" %[^\n]s",temp->tech_area);
	printf("Enter the Project Information \t:\t");
	scanf("%s",temp->project_info);
	return temp;
}

