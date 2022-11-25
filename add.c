
/* ----------------------------  Function Description   ---------------------------------- */
/***
 * Name of the module:   add.c 
 -----------------------------------------
 * Name of the Function:  add_data function
 *  
 * Date of creation:      16/11/2022
 *
 * Author of module:      Hritik Jain, Dinesh A
 *
 * Description of module: 
 *                      In main menu,when add_data selected head pointer and add the Employee details at the end node.

 * Different functions supported in the module: new_employee_detail, add_data_component.

 * Global variables accessed or modified by the module: Access Structure pointer, TS_India_Employee_DB

 * Revision/Modification History:25/11/2022
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
        printf("Enter the Employee details\n");
        printf("Enter the Employee Id\t:\t");
        scanf("%s",temp->emp_id);
        printf("Enter the Employee Name \t:\t");
        scanf(" %[^\n]s",temp->name);
        printf("Enter the Employee Gender \t:\t");
        scanf("%s",temp->gender);
        printf("Enter the Employee Email_ID\t:\t");
        scanf("%s",temp->email_id);
        printf("Enter the Employee Band \t:\t");
        scanf("%s",temp->band);
        printf("Enter the Employee Date of joining \t:\t");
        scanf("%s",temp->doj);
        printf("Enter the Employee Status \t:\t");
        scanf("%s",temp->status);
        printf("Enter the Employee Mobile Number \t:\t");
        scanf("%s",temp->contact_no);
        printf("Enter the Reporting Manager Name \t:\t");
        scanf(" %[^\n]s",temp->reporting_manager);
        printf("Enter the Reportee \t:\t");
        scanf(" %[^\n]s",temp->reportees);
        printf("Enter the Technical Area \t:\t");
        scanf(" %[^\n]s",temp->tech_area);
        printf("Enter the Project Information \t:\t");
        scanf("%s",temp->project_info);
	return temp;
}

