#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct Database
{
        char emp_id[10];
        char name[50];
        char gender[5];
        char email_id[50];
        char band[10];
        char doj[20];
        char status[20];
        char contact_no[15];
        char reporting_manager[50];
        char reportees[50];
        char tech_area[50];
        char project_info[50];
        struct Database *link;
}employee_database;

#include"modify.h"
#include"data_component.h"
#include"add.h"
#include"delete.h"
#include"view.h"

