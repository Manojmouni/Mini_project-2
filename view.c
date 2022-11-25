
/* ----------------------------  Function Description   ---------------------------------- */
/***
 * Name of the module:    view.c 
 -----------------------------------------
 * Name of the Function:  view_data function
 *  
 * Date of creation:      16/11/2022
 *
 * Author of module:      Urmila Lakade
 *
 * Description of module: 
 * 			In main menu,when view_data selected its takes employ ID as a input and
         fetch the data corresponding to input given and display all the fetched details on stdout.

 * Different functions supported in the module: NO.

 * Global variables accessed or modified by the module: Access Structure pointer

 * Revision/Modification History:25/11/2022
 ***/

#include"header.h"

void view_data(char *employ_id,employee_database *head)
{
	int ptr;
	if(head == NULL)//to check head pointer is null or not
	{
		printf("Database Empty\n");
		return;
	}
	else  // if head pointer is not null
	{
		employee_database *temp = head;
		while(temp) // to check upto last emplyoee
		{
			ptr=strcmp(temp->emp_id ,employ_id); //compare given emplyoee id with all emplyoee id from datasheet 
			if(ptr == 0)// if emplyoee id found print the details about emplyoee
			{
				printf("Employee id             : %s\n",temp->emp_id);
				printf("Name                    : %s\n",temp->name);
				printf("Gender                  : %s\n",temp->gender);
				printf("Email_id                : %s\n",temp->email_id);
				printf("Band                    : %s\n",temp->band);
				printf("DOJ                     : %s\n",temp->doj);
				printf("Status                  : %s\n",temp->status);
				printf("Mobile                  : %s\n",temp->contact_no);
				printf("Reporting_manager       : %s\n",temp->reporting_manager);
				printf("Reportee                : %s\n",temp->reportees);
				printf("Tech_area               : %s\n",temp->tech_area);
				printf("Project_info            : %s\n",temp->project_info);

				return;
			}
			else //if employee id not found then increase the pointer to pointed next emplyoee
			{
				temp = temp->link;
			}
		}
		printf("\n~~~~~~~~~~Emplyoee ID Invalid~~~~~~~~~\n");//if upto end emplyoee id not found


	}

}
