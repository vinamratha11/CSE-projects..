
//NOTE First delete all the nodes in SLL and then exit from SLL. Next go to DLL menu

#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<Windows.h>
#include<gl/GL.h>
#include<gl/glu.h>
#include<GL/glut.h>

void renderscene()
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.3, 0.0);

    // First line (Bigger font size)
    char c1[] = "COMPUTER GRAPHICS PROJECT";
    glRasterPos2f(200, 425);
    for (i = 0; c1[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c1[i]);

    // Second line (Same color as the first line)
    char c2[] = "COLLEGE: JSSATEB";
    glRasterPos2f(230.0, 400.0);
    for (i = 0; c2[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c2[i]);

    // Add spacing after the second line
    glRasterPos2f(0, 0); // Reset the raster position

    // Third line (Different color)
    glColor3f(0.0, 0.5, 0.8);
    char c7[] = "TITLE: SINGLY AND DOUBLY LINKED LIST VISUALIZER";
    glRasterPos2f(180, 360);
    for (i = 0; c7[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c7[i]);

    // Fourth line (Different color)
    glColor3f(0.9, 0.2, 0.7);
    char c8[] = "Submitted By,";
    glRasterPos2f(200.0, 325.0);
    for (i = 0; c8[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c8[i]);

    // Fifth line (Different color)
    glColor3f(0.4, 0.7, 0.1);
    char c3[] = "Vi";
    glRasterPos2f(200.0, 300.0);
    for (i = 0; c3[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c3[i]);

    // Sixth line (Different color)
    glColor3f(0.4, 0.7, 0.1);
    char c4[] = "Sup";
    glRasterPos2f(200.0, 275.0);
    for (i = 0; c4[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c4[i]);

    // Seventh line (Different color)
    glColor3f(0.8, 0.4, 0.0);
    char c5[] = "";
    glRasterPos2f(700.0, 250.0);
    for (i = 0; c5[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c5[i]);

    // Eighth line (Different color)
    glColor3f(0.5, 0.1, 0.3);
    char c6[] = "Press right button of mouse to get various options";
    glRasterPos2f(200.0, 200.0);
    for (i = 0; c6[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c6[i]);

    glFlush();
}


void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(0.8);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,2000.0,0.0,400.0);
}
void clearscreen(){
system("cls");
renderscene();
glutPostRedisplay();
glFlush();
}
struct node
{
	int info;
    struct node *link;
	struct node *rlink;
	struct node *llink;
};

struct arr
{
    int p;
    int q;
}ar[20],m[100];

typedef struct node *NODE;
static NODE first = NULL; // First node of Linked List.
static int count = 0,  flag = 1;
int succ = 1, succ1 = 1, ins_succ = 1;
int choice, item, key;
float color[4][3] = {{1.0, 1.0, 1.0}, {0.8, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}};
int drawstringflag = 0, printflag = 1, titleflag = 1;
//static int count=0;
NODE head;
int h[100];


NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("out of memory\n");
		exit(1);
	}
	return temp;
}

void drawstring(float x, float y, char *string, int col, int drawstringflag)
{
    char *c;
    glColor3fv(color[col]);
    glRasterPos2f(x, y);
    if (drawstringflag == 0)
    {
        for(c = string; *c != '\0'; c++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
    else if (drawstringflag == 1)
    {
        for(c = string; *c != '\0'; c++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
    else
    {
        for(c = string; *c != '\0'; c++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void disp()
{
	glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,1.0);
char c[]="List is Empty";
glRasterPos2f(800.0,200.0);
for(int i=0;c[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c[i]);
		glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2i(100,200);
	glVertex2i(100,225);
	glVertex2i(500,225);
	glVertex2i(500,200);
	glEnd();
	glFlush();
}
void title()
{
    glClearColor(192.0, 192.0, 192.0, 1.0);
    drawstring(170.0, 240.0, (char *)"Singly Linked List Visualizer", 1, 2);
    glFlush();

}

void sdisplay()
{
    if(titleflag) // Ensure title is printed only once.
    {
        title(); // Render the Title.
        titleflag = 0;
    }
    int i = 0, j = 0, k = 0, b[20];
    NODE temp;
    glClearColor(192.0, 192.0, 192.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.6);
    drawstring(200.0, 450.0, (char *)"SINGLY LINKED LIST", 1, 0);
    if(first == NULL)
    {
        if(printflag)
        {
            printf("\nEmpty List\n");
            printflag = 0;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        for(k = 0;k < count;k++)
        {
            GLfloat x1 = 50, y1 = 200, x2 = 80, y2 = 225;
            GLfloat x3 = 110, y3 = 250, x4 = 95, y4 = 225;
            GLfloat x5 = 160, y5 = 210, y6 = 240, x6 = 180;
            int pos = 130; // Constant multiplier for positioning.
            if(first->link == NULL)
            {
                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_LINES); // Slash to indicate termination of Linked list.
                    glVertex2i(x2+k*pos, y3);
                    glVertex2i(x3+k*pos, y1);
                glEnd();
            }
            if(temp->link == NULL)
            {
                glColor3f(0.8, 0.2, 0.70);
                glBegin(GL_POLYGON); // Info box.
                    glVertex2i(x1+k*pos, y1);
                    glVertex2i(x1+k*pos, y3);
                    glVertex2i(x2+k*pos, y3);
                    glVertex2i(x2+k*pos, y1);
                glEnd();
                glColor3f(0.0, 0.60, 0.80);
                glBegin(GL_POLYGON); // Next link box.
                    glVertex2i(x2+k*pos, y1);
                    glVertex2i(x2+k*pos, y3);
                    glVertex2i(x3+k*pos, y3);
                    glVertex2i(x3+k*pos, y1);
                glEnd();
                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_LINES); // Slash to indicate termination of Linked list.s
                    glVertex2i(x2+k*pos, y3);
                    glVertex2i(x3+k*pos, y1);
                glEnd();
            }
            else
            {
                glColor3f(0.0f, 0.0f, 0.0f);
                glBegin(GL_LINES); // Line pointing to next node.
                    glVertex2i(x4+k*pos, y4);
                    glVertex2i(x6+k*pos, y4);
                glEnd();
                glColor3f(0.0f, 0.0f, 0.0f);
                glBegin(GL_LINES); // Arrow marks.
                    glVertex2i(x5+k*pos, y6);
                    glVertex2i(x6+k*pos, y4);
                    glVertex2i(x6+k*pos, y4);
                    glVertex2i(x5+k*pos, y5);
                glEnd();
                glColor3f(0.8, 0.20, 0.70);
                glBegin(GL_POLYGON); // Info box.
                    glVertex2i(x1+k*pos, y1);
                    glVertex2i(x1+k*pos, y3);
                    glVertex2i(x2+k*pos, y3);
                    glVertex2i(x2+k*pos, y1);
                glEnd();
                glColor3f(0.0, 0.60, 0.80);
                glBegin(GL_POLYGON); // Next link box.
                    glVertex2i(x2+k*pos, y1);
                    glVertex2i(x2+k*pos, y3);
                    glVertex2i(x3+k*pos, y3);
                    glVertex2i(x3+k*pos, y1);
                glEnd();
            }
            b[j] = temp->info;
            temp = temp->link;
            ar[i].p = b[j]/10;
            ar[i].q = b[j]%10;
            ar[i].p = ar[i].p+48;
            ar[i].q = ar[i].q+48;
            glColor3f(1.0, 1.0, 0.0);
            glRasterPos2f(55.0+k*pos, 215.0);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ar[i].p); // Print Node value.
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ar[i].q);
            drawstring(50.0+k*pos, 185, (char *)"INFO", 1, 1);
            drawstring(95.0+k*pos, 185, (char *)"LINK", 1, 1);
            i++;
            j++;
            glFlush();
        }
    }
}
void lldisplay()
{
    NODE temp1;
    int k;
    if(first == NULL)
    {
        printf("The list is empty!\n");
        return;
    }
    printf("\nContents of Singly Linked List: \n");
    temp1 = first;
    while(temp1 != NULL)
    {
        for(k = 0;k < count;k++)
        {
            printf("%d", temp1->info);
            temp1 = temp1->link;
            printf("\n");
        }
    }
    printf("\n");
}


NODE display(NODE head)
{
    glClear(GL_COLOR_BUFFER_BIT);
    NODE temp, cur;
    int i = 0, k, j = 0, ff, f,fa;

    temp = head->rlink;
    if (temp == head)
    {
        printf("list is empty\n");
        disp();
        return head;
    }
    printf("elements are\n");

    while (temp != head)
    {
        for (k = 0; k < count; k++)
        {
            GLfloat x1 = 100, x2 = 150, x3 = 250, x4 = 300, x5 = 500, x6 = 480, x7 = 20, x9 = 0, x0 = 80;
    h[j]=temp->info;
		printf("%d\n",h[j]);
		glColor3f(0.0,0.0,0.0);
//char c[]="Info";
//glRasterPos2f(210.0,230.0);
//for(int a=0;c[a]!='\0';a++)
	//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,c[a]);
		glColor3f(0.8,0.2,0.7);
		glBegin(GL_POLYGON);
	    glVertex2i(x2+k*300,200);
	    glVertex2i(x2+k*300,225);
	    glVertex2i(x3+k*300,225);
	    glVertex2i(x3+k*300,200);
	    glEnd();
		glColor3f(0.0,0.0,0.0);
//char r[]="rlink";
//glRasterPos2f(380.0,230.0);
//for(int b=0;r[b]!='\0';b++)
//	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,r[b]);
		glColor3f(0.0,0.6,0.8);
	    glBegin(GL_POLYGON);
	    glVertex2i(x3+k*300,225);
	    glVertex2i(x3+k*300,200);
	    glVertex2i(x4+k*300,200);
	    glVertex2i(x4+k*300,225);
	    glEnd();
		glColor3f(0.0,0.0,0.0);
		if (temp->rlink == head)
            {
                // Draw terminating slash in rlink box
                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_LINES);
                 glVertex2i(x3+ k * 300, 225);
                 glVertex2i(x4+ k * 300, 200);
                 glEnd();
            }

//char s[]="llink";
//glRasterPos2f(120.0,230.0);
//for(int d=0;s[d]!='\0';d++)
	//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,s[d]);
		glColor3f(0.0,0.6,0.8);
		glBegin(GL_POLYGON);
	    glVertex2i(x1+k*300,225);
	    glVertex2i(x1+k*300,200);
	    glVertex2i(x2+k*300,200);
	    glVertex2i(x2+k*300,225);
	    glEnd();


		glColor3f(0.0,0.6,0.8);

	    glBegin(GL_LINES);
	    glVertex2i(x1+k*300,207);
	    glVertex2i(x9+k*300,207);
		glVertex2i(x9+k*300,207);
	    glVertex2i(x7+k*300,202);
	    glVertex2i(x9+k*300,207);
	    glVertex2i(x7+k*300,210);
	    glEnd();
	    glColor3f(0.0,0.0,0.0);
	    char ff[]="Head";
        glRasterPos2f(20.0,220.0);
        for(int a=0;ff[a]!='\0';a++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,ff[a]);
	    glColor3f(0.0,0.0,0.0);
	    char fa[]="NULL";
        glRasterPos2f(20.0,190.0);
        for(int a=0;fa[a]!='\0';a++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,fa[a]);
	    glColor3f(0.0,0.6,0.8);
	    glBegin(GL_LINES);
        glVertex2i(x1+k*300,215);
	    glVertex2i(x9+k*300,215);
	    glVertex2i(x1+k*300,215);
        glVertex2i(x0+k*300,210);
	    glVertex2i(x1+k*300,215);
	    glVertex2i(x0+k*300,219);
	    glEnd();
	    glColor3f(0.0,0.0,0.0);
		m[i].p=h[j]/10;
		m[i].q=h[j]%10;
		m[i].p=m[i].p+48;
		m[i].q=m[i].q+48;
		int x8=225;
		glColor3f(0.0,0.0,0.0);
	    glRasterPos2i(x8+k*300,210);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,m[i].p);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,m[i].q);
        drawstring(200.0+k*300, 230, (char *)"INFO", 1, 1);
        drawstring(100.0+k*300, 185, (char *)"LLINK", 1, 1);
        drawstring(250.0+k*300, 185, (char *)"RLINK", 1, 1);
		i++;
		j++;
		temp=temp->rlink;
		glFlush();
		  }
 }


	return head;
}
NODE dinsertfront(NODE head,int item)
{
	NODE temp,cur;
	temp=getnode();
	temp->info=item;
	cur=head->rlink;
	head->rlink=temp;
	temp->llink=head;
	temp->rlink=cur;
	cur->llink=temp;
	return head;

}
NODE dinsertrear(NODE head,int item)
{
	NODE temp,cur;
	temp=getnode();
	temp->info=item;
	cur=head->llink;
	head->llink=temp;
	temp->rlink=head;
	temp->llink=cur;
	cur->rlink=temp;
	return head;
}
NODE dinsertleft(NODE head,int ele)
{
	int item;
	NODE temp,cur,pre;
	if(head->rlink==head)
	{
		printf("list is empty\n");
		count--;
		return head;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(cur->info==ele)
			break;
			cur=cur->rlink;
	}
	if(cur==head)
		{
			printf("%d element not found\n",ele);
			count--;
	        return head;
	}
			printf("enter element to be inserted\n");
				scanf("%d",&item);
				pre=cur->llink;
				temp=getnode();
				temp->info=item;
				temp->llink=pre;
				temp->rlink=cur;
				cur->llink=temp;
				pre->rlink=temp;
				return head;

}
NODE dinsertright(NODE head,int ele)
{
	int item;
	glClear(GL_COLOR_BUFFER_BIT);
	NODE temp,cur,next;
	if(head->rlink==head)
	{
		printf("list is empty\n");
		count--;
		return head;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(cur->info==ele)
		{
			printf("enter element to be inserted\n");
				scanf("%d",&item);
				next=cur->rlink;
				temp=getnode();
				temp->info=item;
				temp->llink=cur;
				temp->rlink=next;
				cur->rlink=temp;
				next->llink=temp;
				return head;
		}
		cur=cur->rlink;
	}
	printf("%d element not found\n",ele);
	count--;
	return head;
}
NODE ddeletfront(NODE head)
{
	NODE cur,next;
	if(head->rlink==head)
	{
		printf("list is empty\n");
		count++;
		return head;
	}
	cur=head->rlink;
	next=cur->rlink;
	head->rlink=next;
	next->llink=head;
	printf("node to b deleted is %d\n",cur->info);
	free(cur);
	return head;
}
NODE ddeletrear(NODE head)
{
	NODE cur,prev;
	if(head->llink==head)
	{
		printf("list is empty\n");
		count++;
		return head;
	}
	cur=head->llink;
	prev=cur->llink;
	head->llink=prev;
	prev->rlink=head;
	printf("node to be deleted is %d\n",cur->info);
	free(cur);
	return head;
}

NODE ddel(NODE head,int ele)
{
	NODE cur,next,pre;
	glClear(GL_COLOR_BUFFER_BIT);
	if(head->rlink==head)
	{
		printf("list is empty\n");
		count++;
		return head;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(cur->info==ele)
			break;
		cur=cur->rlink;
	}
	if(cur==head)
	{
		printf("%d element not found\n",ele);
		count++;
	    return head;
	}
			pre=cur->llink;
			next=cur->rlink;
			printf("%d element found and deleted\n",ele);
			pre->rlink=next;
			next->llink=pre;
			free(cur);
			return head;

}

NODE  insert_front(int item, NODE first)
{
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}

// Insert element from Rear of Linked list.
NODE insert_rear(int item, NODE first)
{
    NODE temp;
    NODE cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if(first == NULL)
    return temp;
    cur = first;
    while(cur->link != NULL)
        cur = cur->link;
    cur->link = temp;
    return first;
}

// Insert node at a specified position.
NODE insert_specified(int item, NODE first)
{
    NODE next, cur, temp;
    temp = getnode();
    temp->info = item;
    if(first == NULL)
    {
        printf("The list is empty! Inserting node at the front...\n");
        temp->link = NULL;
        first = temp;
        return first;
    }
    printf("Enter the key : "); // Key = Node value after which the new node is to be inserted.
    scanf("%d", &key);
    cur = first;
    while(cur != NULL)
    {
        next = cur->link;
        if(cur->info == key)
        {
            printf("Key found!\n");
            cur->link = temp;
            temp->link = next;
            return first;
        }
            cur = cur->link;
    }
   if(cur == NULL)
    {
        printf("Search unsuccessful!\n");
        count--;
        ins_succ = 0;
    }
    return first;
}

// Delete node from Front of Linked List.
NODE delete_front(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("The list is empty, cannot delete!\n");
        count++;
        succ = 0;
        return first;
    }
    temp = first;
    temp = temp->link;
    printf("Deleted item  =  %d \n", first->info);
    free(first);
    return temp;
}

// Delete node from Rear of Linked List.
NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if(first == NULL)
    {
        printf("The list is empty, cannot delete!\n");
        count++;
        succ = 0;
        return first;
    }
        if(first->link == NULL)
    {
        printf("Item to be deleted is %d \n", first->info);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Deleted item  =  %d \n", cur->info);
    free(cur);
    prev->link = NULL;
    return first;
}

// Delete a specified node from Linked List.
NODE delete_specified(NODE first)
{
    NODE prev, cur;
    if(first == NULL)
    {
        printf("The list is empty, cannot delete!\n");
        count++;
        succ = 0;
        return NULL;
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    if(key == first->info)
    {
        cur = first;
        first = first->link;
        free(cur);
        return first;
    }
    prev = NULL;
    cur = first;
    while(cur != NULL)
    {
        if(key == cur->info)
            break;
        prev = cur;
        cur = cur->link;
    }
    if(cur == NULL)
    {
        printf("Search is unsuccessful!\n");
        count++;
        succ1 = 0;
        succ = 0;
        return first;
    }
    prev->link = cur->link;
    free(cur);
    return first;
}

// Option menu for Linked List operations.
void sll_menu(int option)
{
    int item;
    switch(option)
    {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            first = insert_front(item, first);
            count++;
            lldisplay();
            sdisplay();
            drawstring(200.0, 130.0, (char *)"NEW NODE INSERTED", 2, 0);
            break;
        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            first = insert_rear(item, first);
            count++;
            lldisplay();
            sdisplay();
            drawstring(200.0, 130.0, (char *)"NEW NODE INSERTED", 2, 0);
            break;
        case 3:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            ins_succ = 1;
            first = insert_specified(item, first);
            count++;
            lldisplay();
            sdisplay();
            if(!ins_succ)
                drawstring(200.0, 130.0, (char *)"KEY NODE DOESN'T EXIST", 2, 0);
            else
                drawstring(200.0, 130.0, (char *)"NEW NODE INSERTED", 2, 0);
            break;
        case 4:
            succ = 1;
            first = delete_front(first);
            count--;
            lldisplay();
            sdisplay();
            if(succ)
                drawstring(200.0, 130.0, (char *)"NODE DELETED", 2, 0);
            break;
        case 5:
            succ = 1;
            first = delete_rear(first);
            count--;
            lldisplay();
            sdisplay();
            if(succ)
                drawstring(200.0, 130.0, (char *)"NODE DELETED", 2, 0);
            break;
        case 6:
            succ = succ1 = 1;
            first = delete_specified(first);
            count--;
            lldisplay();
            sdisplay();
            if(succ)
                drawstring(200.0, 130.0, (char *)"NODE DELETED", 2, 0);
            if(!succ1)
                drawstring(200.0, 130.0, (char *)"KEY NODE DOESN'T EXIST", 2, 0);
            break;
        case 7:clearscreen();
    }
}

void top_menu(int option)
{
	int ele;
	switch(option)
	{
	case 1:

		printf("enter item to be inserted\n");
				scanf("%d",&ele);
				head=dinsertfront(head,ele);
				count++;
				display(head);
				break;
	case 2:
		printf("enter item to be inserted\n");
				scanf("%d",&ele);
				head=dinsertrear(head,ele);
				count++;
				display(head);
				break;
	case 3:
		printf("enter key to be searched\n");
			    scanf("%d",&ele);
			    head=dinsertleft(head,ele);
			    count++;
			    display(head);
			    break;
	case 4:
		printf("enter key to be searched\n");
			    scanf("%d",&ele);
			    head=dinsertright(head,ele);
			    count++;
			    display(head);
			    break;
	case 5:
		head=ddeletfront(head);
		count--;
		display(head);
		break;
	case 6:
		head=ddeletrear(head);
		count--;
		display(head);
		break;
	case  7:printf("enter key\n");
				scanf("%d",&ele);
				count--;
				head=ddel(head,ele);
				display(head);
				break;
	case 8:exit(0);}}

void mainm(int option){
    int x;
switch(option){
case 1: top_menu(x);
break;
case 2: sll_menu(x);
break;
}}
void minit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char**argv)
{
    int dllMenu,sllMenu;
	head=getnode();
	head->rlink=head;
	head->llink=head;
	head->link=head;
	head->info=NULL;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Linked List");

	dllMenu = glutCreateMenu(top_menu);
	init();
	glutAddMenuEntry("InsertFront",1);
	glutAddMenuEntry("InsertRear",2);
	glutAddMenuEntry("InsertLeft",3);
	glutAddMenuEntry("InsertRight",4);
	glutAddMenuEntry("DeleteFront",5);
	glutAddMenuEntry("DeleteRear",6);
	glutAddMenuEntry("DeleteSpecified",7);
	glutAddMenuEntry("Exit",8);

	sllMenu = glutCreateMenu(sll_menu);
	glutAddMenuEntry("Insert Front", 1);
    glutAddMenuEntry("Insert Rear", 2);
    glutAddMenuEntry("Insert Specified", 3);
    glutAddMenuEntry("Delete Front", 4);
    glutAddMenuEntry("Delete Rear", 5);
    glutAddMenuEntry("Delete Specified", 6);
    glutAddMenuEntry("Exit", 7);
    minit();
    glutCreateMenu(mainm);
	glutAddSubMenu("sll",sllMenu);
	glutAddSubMenu("dll",dllMenu);
    //glutDisplayFunc(sdisplay);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(renderscene);


glutMainLoop();


}
