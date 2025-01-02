#include <stdio.h>
#include <stdbool.h>
#define MAX_LINE_LENGTH 1000
struct Line {
    int line_num;
    char text[MAX_LINE_LENGTH];
};
struct course {
    char name[1024];
    int credit_hours;
    char grade[25];
};
struct subject{
char name[50];};
struct student {
    char name[50];
    char id[25];
    char bd[25];
    char email[50];
    char home_location[1000];
    int pin;
    float gpa;
    int num_courses;
    int esp;
    char section[100];
    float highschool_degree;
    float degree_percent;
    struct course courses[10];
};
struct student students[100];
int num_students = 0;
int num_courses = 0;
char name[100],random_variable[1024];
char RegistrationNumber1[20];
display_student(){
    Title();
    printf("\t\tEnter the student's ID to display: ");
    scanf("%s",&RegistrationNumber1);
    Title();
    strcpy(name, RegistrationNumber1);
    FILE *pfile;
    pfile = fopen(strcat(name,".txt"), "r");
    if (pfile==NULL){printf("That's registration number is not located please check your information and try again... ");display_student();}
    else{
    int line_number_to_skip = 1;
    int start,end;
    int current_line = 0;
    char line[100];
    while (fgets(line, sizeof(line), pfile) != NULL) {
        current_line++;
        if (current_line != line_number_to_skip) {
            printf("\t\t%s", line);
        }
    }
    printf("\n\t\tPress enter to continue...");
    getch();
    Title();
   staff_menu();}

}
view_students(){
    Title();
    FILE *fp;
    fp=fopen("view_students.txt","r+");
    int line_number_to_skip = 99;
    int start,end;
    int current_line = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        current_line++;
        if (current_line != line_number_to_skip) {
            printf("\t\t%s", line);
        }
    }
    printf("\n\t\tPress Enter to continue...\n");
    getch();

    staff_menu();


}
staff_menu(){
    int o;
 printf("\t\t1.Register for new student\n\t\t2.Add new courses for a new student(must be registered)\n\t\t3.Display a student record\n\t\t4.Edit student(currently unavailable)\n\t\t5.Delete a student record\n\t\t6.GPA calculator\n\t\t7.Show registered students\n\t\t8.Main menu\n\t\t9.Exit\n\t\tPlease Choose an option: ");
    scanf("%d",&o);
    switch(o)
    {
    case 2:
        add_student();break;
    case 4:
        printf("\n\t\tUnder development...\n");getch();Title();staff_menu();break;
    case 5:
        delete_student();break;
    case 1:
        Registration();break;
    case 6:
        gpa_calc();break;
    case 7:
        view_students();break;
    case 8:
        main();break;
    case 3:
        display_student();break;
    case 9:
        printf("\t\tAre you sure ?\n\t\t1.YES\n\t\t2.NO\n\t\tChoose 1 or 2 : ");
        int o;
                scanf("%d",&o);
                if (o==1){printf("\t\tExiting the program...");exit(0);}
                else Title();staff_menu();
                break;

    default : staff_menu();break;
    }}
print_transcript(){
    Title();
    strcpy(name, RegistrationNumber1);
    FILE *pfile;
    pfile = fopen(strcat(name,".txt"), "r");
    int line_number_to_skip = 1;
    int start,end;
    int current_line = 0;
    char line[100];
    while (fgets(line, sizeof(line), pfile) != NULL) {
        current_line++;
        if (current_line != line_number_to_skip) {
            printf("\t\t%s", line);
        }
    }
    printf("\n\t\tPress enter to continue...");
    getch();
    int x;
    m:
    printf("\n\t\t1.GPA calculator\n\t\t2.Print transcript\n\t\t3.Main Menu\n\t\t4.Exit\n");
    printf("\t\tPick an option: ");
    scanf("%d",&x);
    switch (x){
    case 1:gpa_calc();
    break;
    case 2:print_transcript();
    break;
    case 3:main();
    break;
    case 4:exit(0);
    break;
    default:goto m;break;}

}
delete_student(){
    char id_del[50];
    printf("\t\tEnter student's id: ");
    scanf("%s",&id_del);
    if (remove(strcat(id_del,".txt")) == 0) {
        printf("\t\tFile deleted successfully.\n");
    } else {
        printf("\t\tError deleting file.\n");
    }
    printf("\t\tPress enter to continue...");
    getch();
    Title();
    staff_menu();
    }
gpa_calc(){
	//_________________VARIABLE________________//

	int grade, course_number_3_hours, hours_3_hours = 45, course_number_2_hours, hours_2_hours = 30,o;
	float point=0.0, sum_3_hours = 0.0, sum_2_hours = 0.0, GPA, total_sum_of_point = 0.0, total_credit_hours;
	struct subject subject3[10];
    struct subject subject2[10];

	//________________INPUT & OUTPUT______________//

	Title();
	printf("\t\tEnter number of courses (3 hours):");
	scanf_s("%d", &course_number_3_hours);
	int x=course_number_3_hours,arr[4],j=0;

	printf("\t\t1.Advanced physics\n\t\t2.Discrete structures\n\t\t3.Calculus\n\t\t4.Problem solving\n\t\tChoose which one you want to add a mark to it:-\n");
    while (x--)
    {   printf("\n\t\tSubject number [%d]: ",j+1);
        scanf("%d",&arr[j]);
        if (arr[j]==1){strcpy(subject3[j].name,"Advanced physics");}
        else if (arr[j]==2){strcpy(subject3[j].name,"Discrete structures");}
        else if (arr[j]==3){strcpy(subject3[j].name,"Calculus");}
        else if (arr[j]==4){strcpy(subject3[j].name,"Problem solving");}
        j++;
    }
    Title();
	printf("\n\t\tEnter number of courses (2 hours): ");
	scanf_s("%d", &course_number_2_hours);
    int y=course_number_2_hours,arr2[4];
    j=0;
    printf("\t\t1.Communication skills\n\t\t2.ESP\n\t\t3.Entrepreneurship skills\n\t\tChoose which one you want to add a mark to it:-\n");
    while (y--)
    {   printf("\n\t\tSubject number [%d]: ",j+1);
        scanf("%d",&arr2[j]);
        if (arr2[j]==1){strcpy(subject2[j].name,"Communication skills");}
        else if (arr2[j]==2){strcpy(subject2[j].name,"ESP");}
        else if (arr2[j]==3){strcpy(subject2[j].name,"Entrepreneurship skills");}
        j++;
    }

    Title();

	//________________CALCULATE POIENT 3 HOURS__________//

	for(int i=0;i< course_number_3_hours;i++)
	{
	printf("\n\t\tStudent mark in %s (3 hours): ",subject3[i].name);
	scanf_s("%d", &grade);

	if      (grade <= 100&& grade >= 96)
	{
		point = hours_3_hours * 4;
	}
	else if (grade < 96 && grade >= 92)
	{
		point = hours_3_hours * 3.7;
	}
	else if (grade < 92 && grade >= 88)
	{
		point = hours_3_hours * 3.4;
	}
	else if (grade < 88 && grade >= 84)
	{
		point = hours_3_hours * 3.2;
	}
	else if (grade < 84 && grade >= 80)
	{
		point = hours_3_hours * 3;
	}
	else if (grade < 80 && grade >= 76)
	{
		point = hours_3_hours * 2.8;
	}
	else if (grade < 76 && grade >= 72)
	{
		point = hours_3_hours * 2.6;
	}
	else if (grade < 72 && grade >= 68)
	{
		point = hours_3_hours * 2.4;
	}
	else if (grade < 68 && grade >= 64)
	{
		point = hours_3_hours * 2.2;
	}
	else if (grade < 64 && grade >= 60)
	{
		point = hours_3_hours * 2;
	}
	else if (grade < 60 && grade >= 55)
	{
		point = hours_3_hours * 1.5;
	}
	else if (grade < 55 && grade >= 50)
	{
		point = hours_3_hours * 1;
	}
	else if (grade < 50)
	{
		point = hours_3_hours * 0;
	}

	sum_3_hours += point;
	}

	//________________CALCULATE POIENT 2 HOURS___________//

	for (int j = 0; j < course_number_2_hours; j++)
	{
        printf("\n\t\tStudent mark in %s (2 hours):",subject2[j].name);
		scanf_s("%d", &grade);
		if      (grade <= 100 && grade >= 96)
		{
			point = hours_2_hours * 4;
		}
		else if (grade < 96 && grade >= 92)
		{
			point = hours_2_hours * 3.7;
		}
		else if (grade < 92 && grade >= 88)
		{
			point = hours_2_hours * 3.4;
		}
		else if (grade < 88 && grade >= 84)
		{
			point = hours_2_hours * 3.2;
		}
		else if (grade < 84 && grade >= 80)
		{
			point = hours_2_hours * 3;
		}
		else if (grade < 80 && grade >= 76)
		{
			point = hours_2_hours * 2.8;
		}
		else if (grade < 76 && grade >= 72)
		{
			point = hours_2_hours * 2.6;
		}
		else if (grade < 72 && grade >= 68)
		{
			point = hours_2_hours * 2.4;
		}
		else if (grade < 68 && grade >= 64)
		{
			point = hours_2_hours * 2.2;
		}
		else if (grade < 64 && grade >= 60)
		{
			point = hours_2_hours * 2;
		}
		else if (grade < 60 && grade >= 55)
		{
			point = hours_2_hours * 1.5;
		}
		else if (grade < 55 && grade >= 50)
		{
			point = hours_2_hours * 1;
		}
		else if (grade < 50)
		{
			point = hours_2_hours * 0;
		}

		sum_2_hours += point;
	}

	//________________CALCULATE TOTAL POINTS___________//

	total_sum_of_point = (sum_3_hours)+(sum_2_hours);

	//________________CALCULATE GPA_____________//

	total_credit_hours = (course_number_3_hours * 45) + (course_number_2_hours * 30);
	GPA = total_sum_of_point / total_credit_hours;
	printf("\n\t\tStudent GPA: %0.2f \n", GPA);
	printf("\t\t1.Calculate GPA again\n\t\t2.Main Menu\n\t\t3.Exit\n");
	printf("\t\tPick a choice: ");
	scanf("%d",&o);
	switch(o)
	{
    case 1:
        gpa_calc();
        break;
    case 2:
        main();
        break;
    case 3:exit(0);
	}

}
add_student() {
    char temp[25];
    char us[50];
    Title();
    int choice,o,x;
    FILE *fp,*pfile;
    struct student new_student;
    printf("\t\tEnter student ID: ");
    fflush(stdin);
    gets(new_student.id);
    strcpy(temp,new_student.id);
    pfile = fopen(strcat(temp,".txt"), "r");
    if(pfile==NULL)
    {
        int choice;
        printf("\t\tThis student doesn't exist or hasn't registered yet");
        p2:
        printf("\n\t\t1.Try Again\n\t\t2.Main Menu\n\t\t3.Exit\n\t\tPick a choice: ");
        scanf("%d", &choice);
    switch(choice){
    case 1:
    add_student();break;
    case 2:
    main();break;
    case 3:exit(0);
    default: goto p2;
    }
    }
    else{
    strcpy(temp,new_student.id);
    fp = fopen(strcat(temp,".txt"), "a");




    printf("\t\tEnter number of courses: ");
    scanf("%d", &new_student.num_courses);
    for (int i = 0; i < new_student.num_courses; i++) {
        printf("\t\tEnter course name: ");
        fflush(stdin);
        gets(new_student.courses[i].name);
        printf("\t\tEnter credit hours: ");
        scanf("%d",&new_student.courses[i].credit_hours);
        }

        for(int i=0;i<new_student.num_courses;i++)
        {
            fprintf(fp,"%-32s\t%d\n",new_student.courses[i].name,new_student.courses[i].credit_hours);
        }
            students[num_students++] = new_student;
            printf("\t\tStudent added successfully!\n");
            printf("\t\tDo you want to add another student? ( 1.Yes / 2.No ): ");
            scanf("%d",&choice);
            switch(choice)
            {
            case(1):
                add_student();
                break;
            case(2):
                Title();
                staff_menu();
                break;

    };
}}
Registration(){
    system("cls");
    Title();
    struct student stu;
    char us[50],temp[100];
    int x;
    printf("\t\t\t\t\twelcome to registration page\n");
    printf("\t\t\t\t\t-----------------------------\n");
    printf("\t\tRegistration Number: ");
    scanf("%s", &stu.id);
    strcpy(name,stu.id);
    strcpy(temp,stu.id);
    FILE *pfile,*fp;
    fp=fopen(strcat(temp,".txt"),"r");
    fscanf(fp, "%s", &us);
     if(strcmp(stu.id,us)==0){
        printf("\n\t\tThis student is already registered");
        printf("\n\t\t1.Try Again\n\t\t2.Main Menu\n\t\t3.Exit\n\t\tPlease enter your choice : ");
        scanf("%d", &x);
        switch(x){
    case 1:
        Registration();break;
    case 2:
        main();break;
    case 3:exit(0);
        }
        }
    else{

    pfile = fopen(strcat(name, ".txt"), "w");
    printf("\t\tPIN code: " );
    scanf("%d", &stu.pin);
    printf("\t\tFull name: " );
    fflush(stdin);
    gets(stu.name);
    printf("\t\tBirthday: " );
    scanf("%s", &stu.bd);
    printf("\t\tEmail: " );
    scanf("%s", &stu.email);
    printf("\t\tHome location: " );
    fflush(stdin);
    gets(stu.home_location);
    do{
    printf("\t\tDegree of test to set for ESP level (maximum is 50): ");
    scanf("%d",&stu.esp);
    }while(stu.esp<0 || stu.esp>50);
    printf("\t\tHigh school section: ");
    fflush(stdin);
    gets(stu.section);
    do{
    printf("\t\tHigh school degree(can't be more than 410 and should be more than 246 or 60%): ");
    scanf("%f",&stu.highschool_degree);
    }while(stu.highschool_degree<246 || stu.highschool_degree>410);
    stu.degree_percent=(stu.highschool_degree/410)*100;
    fprintf(pfile, "%s %d\nStudent's ID: %s\nStudent's Name: %s\nBirthday: %s\nStudent's E-mail: %s\nStudent's Address: %s\n", stu.id, stu.pin,stu.id,stu.name,stu.bd,stu.email,stu.home_location);
    if(stu.esp>20)
    {
        fprintf(pfile,"ESP level: 1\n");
    }
    else{
        fprintf(pfile,"ESP level: 0\n");
    }
    fprintf(pfile,"High school section: %s\nHigh School degree: %0.1f\nHigh school percentage: %0.2f%%",stu.section,stu.highschool_degree,stu.degree_percent);
    fprintf(pfile,"\nFaculty of computing and information technology --> Deparment of computer science\n");
    fprintf(pfile,"Course name\t\t\tCredit hours\n");
    fclose(pfile);
    FILE *opf;
    opf=fopen("view_students.txt","a");
    fprintf(opf,"\n%s\t\t%s",stu.name,stu.id);
    fclose(opf);
    printf("\t\tRegistration successfully...\n\t\tDo you want to register for another student? \n\t\t1.YES\n\t\t2.NO : ");
    int o;
    scanf("%d",&o);
    if (o==1){Registration();}
    Title();
    staff_menu();
    }
}
Title(){
    system("cls");
    printf("\t\t==============================================================================\n\n");
    printf("\t\t\tArab Academy for Science, Technology and Maritime Transport\n\n");
    printf("\t\t==============================================================================\n\n");
    printf("\n");
}
login_staff(){
system("cls");

    int u = strlen(RegistrationNumber1);
    char us[20];
    char password1[20];
    int p = strlen(password1);
    char pa[20];
    Title();
    printf("\t\t\t\t\tWelcome to staff login page!\n");
    printf("\t\t\t\t\t------------------------\n");
    printf("\t\tRegistration Number: ");
    scanf("%s",&RegistrationNumber1);
    printf("\t\tPassword: ");
    scanf("%s",&password1);


    strcpy(name, RegistrationNumber1);

    FILE *pfile;

    pfile = fopen(strcat(name,"s.txt"), "r");
    fscanf(pfile, "%s %s", &us, &pa);

    if(strcmp(RegistrationNumber1,us)==0 && strcmp(password1,pa)==0)
        return true;
        else
        return false;
    fclose(pfile);
}
login_student(){
system("cls");

    int u = strlen(RegistrationNumber1);
    char us[20];
    char password1[20];
    int p = strlen(password1);
    char pa[20];
    Title();
    printf("\t\t\t\t\tWelcome to student login page!\n");
    printf("\t\t\t\t\t------------------------\n");
    printf("\t\tRegistration Number: ");
    scanf("%s",&RegistrationNumber1);
    printf("\t\tPassword: ");
    scanf("%s",&password1);


    strcpy(name, RegistrationNumber1);

    FILE *pfile;

    pfile = fopen(strcat(name,".txt"), "r");

    fscanf(pfile, "%s %s", &us, &pa);

    if(strcmp(RegistrationNumber1,us)==0 && strcmp(password1,pa)==0)
        return true;
        else
        return false;
    fclose(pfile);
}
staff(){
    FILE *pfile;
    if (login_staff()){printf("\t\tLogin sucessfully...\n");}
    else{
            int x;
            p2:
            printf("\t\tWrong inputs\n\t\t1.Try Again\n\t\t2.Main Menu\n\t\t3.Exit\n\t\tPick a choice: ");
            scanf("%d", &x);
    switch(x){
    case 1:
    staff();break;
    case 2:
    main();break;
    case 3:exit(0);
    default: goto p2;
    }


    }
    getch();
    strcpy(name, RegistrationNumber1);
    pfile = fopen(strcat(name,"s.txt"), "r");
    if (pfile==NULL){printf("Error: could not open file.\n");}
    int line_number_to_skip = 1;
    int current_line = 0;
    char line[100];
    system("cls");
    Title();
    while (fgets(line, sizeof(line), pfile) != NULL) {
        current_line++;
        if (current_line != line_number_to_skip) {
            printf("\t\tWelcome %s\n", line);
        }
    }

    staff_menu();
    fclose(pfile);

    };
student(){

    FILE *pfile;
    if (login_student()){printf("\t\tLogin sucessfully...\n");}
    else{
            int x;
            p3:
            printf("\t\tWrong inputs\n\t\t1.Try Again\n\t\t2.Main Menu\n\t\t3.Exit\n\t\tPick a choice: ");
            scanf("%d", &x);
    switch(x){
case 1:
    student();break;
    case 2:
        main();break;
    case 3:exit(0);
    default: goto p3;
    }


    }
    strcpy(name, RegistrationNumber1);
    pfile = fopen(strcat(name,".txt"), "r");
    if (pfile==NULL){printf("Error: could not open file.\n");}
    Title();
    int line_number_to_skip = 1;
    int start,end;
    int current_line = 0;
    char line[100];
    while (fgets(line, sizeof(line), pfile) != NULL) {
        current_line++;
        if (current_line == 2||current_line==3) {
            printf("\t\t%s", line);
        }
    }

    int x;
    m:
    printf("\n\t\t1.GPA calculator\n\t\t2.Print transcript\n\t\t3.Main Menu\n");
    printf("\t\tPick an option: ");
    scanf("%d",&x);
    switch (x){
    case 1:gpa_calc();
    break;
    case 2:print_transcript();
    break;
    case 3:main();
    break;
    default:goto m;break;

    }
    fclose(pfile);

    };
int main (){
/*Edit_login_student(){
system("cls");

    int u = strlen(RegistrationNumber1);
    char us[20];
    char pa[20];
    Title();
    printf("\t\t\t\t\tEdite Student\n");
    printf("\t\t\t\t\t------------------------\n");
    printf("\t\tRegistration Number: ");
    scanf("%s",&RegistrationNumber1);
    strcpy(name, RegistrationNumber1);

    FILE *pfile;

    pfile = fopen(strcat(name,".txt"), "r");

    fscanf(pfile, "%s", &us);

    if(strcmp(RegistrationNumber1,us)==0)
        return true;
        else
        return false;
    fclose(pfile);
}
edit_student() {
   Title();
    FILE *pfile, *temp;
    struct Line new_line;
    struct course subject[10];
    char id_edit[25],num[2048]={0,1,2,3,4,5,6,7};
    int edited_subjects,sub_to_edit,i=0,current_line=1;
    printf("\t\tEnter student's id to edit: ");
    scanf("%s",&id_edit);
    Title();
    strcpy(name,id_edit);
    pfile=fopen(strcat(name,".txt"),"r+");
    temp=fopen("temp.txt","w");
    char buffer[1024],new_course_name[100],buffer2[1024];
    int start=6,end=12;
    int line_num = 0,new_course_hours;
    char line[100];
    while (fgets(buffer, sizeof(buffer), pfile) != NULL && i<1024) {
        line_num++;
        if (line_num < start) {
            continue;
        }
        sscanf(buffer,"%s %d %s",subject[i].name,&subject[i].credit_hours,subject[i].grade);
        i++;
        if (line_num > end) {
            break;
        }
        printf("\t\t%s", buffer);
    }
    printf("\t\tEnter how many subjects you want to edit: ");
    scanf("%d",&edited_subjects);
    char c[edited_subjects];
    for(int i=0;i<edited_subjects;i++)
    {
        printf("\t\tEnter the number of the subject you want to edit: ");
        scanf("%s",&c[i]);
        new_line.line_num=c[i]-'0';
        for(int j=0;j<7;j++){
            if(c[i]==subject[j].name[0])
            {
                int NumOfSub=j+1;
                printf("\t\tEnter the new course name: ");
                fflush(stdin);
                gets(random_variable);
                strcpy(subject[j].name,random_variable);
                fprintf(pfile,"%d.%s",NumOfSub,subject[j].name);

            }
        }

    }
     while (fgets(buffer, sizeof(buffer), pfile) != NULL) {
     for(int j=0;j<7;j++)
     {
          if (current_line == new_line.line_num)
          {
              if(strcmp(buffer,subject[j].name)!=0)
              {
                  fputs(subject[j].name,temp);
              }
              else
              {
                  fputs(buffer,temp);
              }
          }
          else
          {
              fputs(buffer,temp);
          }
     }
     current_line++;
     }
     fclose(pfile);
     fclose(temp);
     if (remove(name) != 0) {
        perror("Error deleting original file");
        exit(EXIT_FAILURE);
    }
     if (rename("temp.txt", name) != 0) {
        perror("Error renaming temporary file");
        exit(0);
    }

}*/
        int choice,o;
        Title();
        printf("\t\t\t\t\tWelcome to main menu\n\t\t1 - Staff\n\t\t2 - Student\n\t\t3 - Exit\n\t\tPlease enter your choice : ");
        while (scanf("%d",&choice)!=1||choice>3||choice<1){while(getchar()!='\n');printf("\t\twrong input please try again: ");}
    switch (choice)
        {
            case(1):
                staff();
                break;
            case(2):
                student();
                break;
            case(3):
                printf("\t\tAre you sure ?\n\t\t1.YES\n\t\t2.NO\n\t\tChoose 1 or 2 : ");
                scanf("%d",&o);
                if (o==1){printf("\t\tExiting the program...");exit(0);}
                else main();
                break;

        }


    return 0;
    }
