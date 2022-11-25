#include"header.h"

int main()
{
	employee_database *hptr = 0;
	data_component(&hptr);
	char employee_id[10];

	int choice, cnt=0;
	while(1)
	{
		printf("\n-------------------------------------------------------\n");
		printf("1.Add, 2.View, 3.Modify, 4.Delete, 5.Exit\n ");
		printf("Please enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	add_data(&hptr);
				break;
				
			case 2: printf("Enter the Employee ID :");
				scanf("%s",employee_id);
				view_data(employee_id,hptr);
				break;

			case 3: modify_data(&hptr); 
				break;

			case 4: delete_data(&hptr);
				break;

			case 5: return 0;

			default:cnt++;
				if(cnt==1)
				{
					printf("You have 2 attempts:\n");
					continue;
				}
				else if(cnt==2)
				{
					printf("You have 1 attempts:\n");
					continue;
				}
				else
					printf("You dont have any more attempts.\n");
				return 0;

		}
	}
}
