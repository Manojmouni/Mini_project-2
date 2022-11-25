#include"header.h"

void view(employee_database *new)
{
	while(new!=NULL)
	{
		printf("\n");
		printf("-----------------------------------------------------------------\n");
		printf("Employee id             : %s\n",new->emp_id);
		printf("Name                    : %s\n",new->name);
		printf("Gender                  : %s\n",new->gender);
		printf("Email_id                : %s\n",new->email_id);
		printf("Band                    : %s\n",new->band);
		printf("DOJ                     : %s\n",new->doj);
		printf("Status                  : %s\n",new->status);
		printf("Mobile                  : %s\n",new->contact_no);
		printf("Reporting_manager       : %s\n",new->reporting_manager);
		printf("Reportee                : %s\n",new->reportees);
		printf("Tech_area               : %s\n",new->tech_area);
		printf("Project_info            : %s\n",new->project_info);
		
		new = new->link;
	}
}
