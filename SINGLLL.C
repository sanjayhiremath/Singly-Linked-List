#include<stdio.h>

#include<conio.h>

#include<malloc.h>

#include<process.h>

#define PF printf
#define SF scanf
struct cnode {
  int info;
  struct cnode * nxt;
};
void newnode();
struct cnode * start, * cur, * temp;

void create();
void insertbeg();
void insertend();
void insertafter();
void insertbefore();
void insertpos();
void search();
void delete1();
void display();
void erase();
void newnode();
void count();
void reverse();
void sort();
void delpos();
void insdesc();
void insasc();
void rev();
main() {
  int ch, i;
  start = NULL;
  while (1) {
    clrscr();
    PF(".............................SINGLY LINKED LIST.........................");
    PF("\nPRESS 1:     CREATE\nPRESS 2:     INSERT AT BEGINNING\nPRESS 3:     INSERT AT END\nPRESS 4:     INSERT AFTER\nPRESS 5:     INSERT BEFORE\nPRESS 6:     INSERT AT GIVEN POSITION\nPRESS 7:     COUNT THE NODES\nPRESS 8:     SEARCH THE NODE\nPRESS 9:     DELETE NODE\nPRESS 10:    DISPLAY REVESE LINKED LIST\nPRESS 11:    DISPLAY LINKED LIST\nPRESS 12:    DESTROY LINKED LIST\nPRESS 13:    SORT THE LIST\nPRESS 14:    INSERT IN ASCENDING ORDER\nPRESS 15:    INSERT IN DESCENDING ORDER\nPRESS 16:    DELETE AT GIVEN POSITION\nPRESS 17:    REVERSE LINKED LIST\nPRESS 0:     EXIT");

    PF("\nENTER YOUR CHOICE:");
    SF("%d", & ch);
    switch (ch) {
    case 0:
      exit(0);
    case 1:
      create();
      break;
    case 2:
      insertbeg();
      break;
    case 3:
      insertend();
      break;
    case 4:
      insertafter();
      break;
    case 5:
      insertbefore();
      break;
    case 6:
      insertpos();
      break;
    case 7:
      count();
      break;
    case 8:
      search();
      break;
    case 9:
      delete1();
      break;
    case 10:
      reverse(start);
      break;
    case 11:
      display();
      break;
    case 12:
      erase();
      break;
    case 13:
      sort();
      break;
    case 14:
      insasc();
      break;
    case 15:
      insdesc();
      break;
    case 16:
      delpos();
      break;
    case 17:
      rev();
      break;
    default:
      PF("\nWrong Choice");
    }
    getch();
  }
}
void newnode() {
  cur = (struct cnode * ) malloc(sizeof(struct cnode));
  if (cur == NULL) {
    PF("\nSORRY..MEMORY NOT AVAILABLE...");
    return;
  }
  PF("Enter info ");
  SF("%d", & cur -> info);
  cur -> nxt = NULL;
}

void create() {
  int n, i;
  PF("Enter how much nodes you want to create ");
  SF("%d", & n);
  for (i = 1; i <= n; i++) {
    newnode();
    //insert new node at end
    /*   if(i==1)
       {
         start=cur;
    //     start->nxt=NULL;

       }
       else
       {
        temp->nxt=cur;
          cur->nxt=NULL;
        }
       temp=cur;
      }
      */
    //insert cur node at beginning

    if (start == NULL) {
      start = cur;
      start -> nxt = NULL;
    } else {
      cur -> nxt = temp;
    }
    temp = cur;
  }
  start = temp;

  // insertend();

  // }
  PF("\nLINKED LIST IS CREATED....");
}
void insertbeg() {
  newnode();
  if (start == NULL) {
    start = cur;
    PF("\n%d IS SUCCESSFULLY INSERTED AT BEGINNING..", cur -> info);
    return;
  }
  cur -> nxt = start;
  start = cur;
  PF("\n%d IS SUCCESSFULLY INSERTED AT BEGINNING..", cur -> info);
}
void insertend() {
  newnode();
  if (start == NULL) {
    start = cur;
    PF("\n%d IS SUCCESSFULLY INSERTED AT END..", cur -> info);
    return;
  }
  temp = start;
  while (temp -> nxt != NULL) {
    temp = temp -> nxt;
  }
  temp -> nxt = cur;
  PF("\n%d IS SUCCESSFULLY INSERTED AT END..", cur -> info);
}
void insertafter() {
  struct cnode * t, * nxt1;
  int se, pos;
  if (start == NULL) {
    PF("\nLL IS EMPTY");
    return;
  }
  pos = 0;
  t = start;

  PF("\nENTER INFO AFTER YOU WANT TO INSERT:");
  SF("%d", & se);

  while (t != NULL) {
    if (t -> info == se) {
      newnode();
      cur -> nxt = t -> nxt;
      t -> nxt = cur;
      PF("\n%d IS PROPERLY  INSERTED AFTER %d.", cur -> info, se);
      return;
    }
    t = t -> nxt;
  }
  PF("\n%d IS NOT PRESENT IN LINKED LIST..", se);
}
void insertbefore() {
  struct cnode * t;
  int se, pos;
  if (start == NULL) {
    PF("\nLL IS EMPTY");
    return;
  }
  t = start;
  PF("\nENTER INFO BEFORE YOU WANT TO INSERT:");
  SF("%d", & se);

  if (se == start -> info) {
    insertbeg();
    return;
  }

  while (t -> nxt != NULL) {
    if (t -> nxt -> info == se) {
      newnode();
      cur -> nxt = t -> nxt;
      t -> nxt = cur;
      PF("\nPROPERLY INSERTED BEFORE %d.", se);
      return;
    }
    t = t -> nxt;
  }
  PF("\n%d IS NOT PRESENT IN LINKED LIST..", se);
}
/*
void insertpos()
{
 int pos,i;
 if(start==NULL)
 {
  PF("\nSORRY LINKED LIST IS EMPTY...");
  return;
 }
 PF("\nENTER POSITION IN WHICH YOU WANT TO INSERT A NODE(START AT 1):");
 SF("%d",&pos);
 newnode();
 if(pos==1 || pos==0)
 {
 cur->nxt=start;
 start=cur;
 PF("\n%d IS PROPERLY INSERTED AT POS %d",cur->info,pos) ;
 return;
 }

 temp=start;
 for(i=1;i<pos-1 && temp!=NULL;i++)
   temp=temp->nxt;
 if(temp==NULL)
 {
   PF("\nNOT A PROPER POSITION");
   return;
 }
 cur->nxt=temp->nxt;
 temp->nxt=cur;
  PF("\n%d IS PROPERLY INSERTED AT POS %d",cur->info,pos) ;
}
*/
void insertpos() {
  int pos, i = 1, u = 0;
  struct cnode * t;

  if (start == NULL) {
    PF("\nSORRY LINKED LIST IS EMPTY...");
    return;
  }
  t = start;
  PF("\nENTER POSITION IN WHICH YOU WANT TO INSERT A NODE(START AT 1):");
  SF("%d", & pos);
  while (t != NULL) {
    u++;
    t = t -> nxt;
  }
  if (pos > u + 1) {
    PF("\nNOT A PROPER POSITION..");
    return;
  }
  if (pos == 1 || pos == 0) {
    insertbeg();
    return;
  }
  t = start;
  while (i != pos - 1) {
    t = t -> nxt;
    i++;
  }
  newnode();
  cur -> nxt = t -> nxt;
  t -> nxt = cur;
  PF("\n%d IS PROPERLY INSERTED AT POS %d", cur -> info, pos);
}
void sort() {
  struct cnode * p, * q, * r, * s, * end, * t, * c;
  int cnt = 0, te, i, j;
  if (start == NULL) {
    PF("\nLINKED LIST IS NOT AVAILABLE...");
    return;
  }
  //selection sort by exchanging data
  /* for(p=start;p->nxt!=NULL;p=p->nxt)
   {
     for(q=p->nxt;q!=NULL;q=q->nxt)
     {
       if(p->info>q->info)
       {
         t=p->info;
         p->info=q->info;
         q->info=t;
       }
     }
   }
   by rearranging links
    for(r=p=start;p->nxt!=NULL;r=p,p=p->nxt)
   {
     for(s=q=p->nxt;q!=NULL;s=q,q=q->nxt)
     {
       if(p->info>q->info)
       {
         t=p->info;
         p->info=q->info;
         q->info=t;
         if(p!=start)
  	  r->nxt=q;
        else

         s->nxt=p;
         if(p==start)
  	  start=q;
  	t=p;
  	p=q;
  	q=t;
       }
     }
   }*/
  //bubble sort
  /* for(end=NULL;end!=start->nxt;end=q)
   {
     for(p=start;p->nxt!=end;p=p->nxt)
     {
       q=p->nxt;
       if(p->info>q->info)
       {
         t=p->info;
         p->info=q->info;
         q->info=t;
       }
     }
   }*/
  p = start;
  while (p != NULL) {
    cnt++;
    p = p -> nxt;
  }
  t = start;
  for (i = 0; i < cnt - 1; i++) {
    c = t -> nxt;
    for (j = i + 1; j < cnt; j++) {
      if (t -> info > c -> info) {
        te = t -> info;
        t -> info = c -> info;
        c -> info = te;
      }
      c = c -> nxt;
    }
  }

  PF("\nLINKED LIST IS SORTED PRESS 1 TO DISPLAY LINKED LIST..");
  SF("%d", & i);
  if (i == 1) {
    display();
  }
}
void count() {
  int i = 0;

  if (start == NULL) {
    PF("\nLINKED LIST IS EMPTY...");
    return;
  }
  temp = start;
  while (temp != NULL) {
    i++;
    temp = temp -> nxt;
  }
  PF("NUMBER OF NODES IN LINKED LIST=%d", i);
}
void search() {
  int se, i;
  if (start == NULL) {
    PF("\nLINKED LIST IS NOT AVAILABLE...");
    return;
  }
  i = 0;
  PF("\nENTER SEARCH ELEMENT");
  SF("%d", & se);
  temp = start;
  while (temp != NULL) {
    i++;
    if (temp -> info == se) {
      PF("%d IS FOUND AT %d LOCATION.", se, i);
      return;
    }
    temp = temp -> nxt;
  }
  PF("%d IS NOT FOUND IN LINKED LIST", se);
}
void delete1() {
  int pos;
  struct cnode * pr;
  if (start == NULL) {
    PF("\nSORRY LINKED LIST IS EMPTY...");
    return;
  }
  PF("\nENTER ELEMENT YOU WANT TO DELETE..");
  SF("%d", & pos);
  pr = temp = start;
  if (pos == start -> info) {
    start = start -> nxt;
    free(temp);
    return;
  }
  // temp=start;
  while (temp != NULL) {
    if (pos == temp -> info) {
      pr -> nxt = temp -> nxt;
      free(temp);
      PF("%d IS SUCCESSFULLY DELTETED FROM LINKED LIST.", pos);
      return;
    }
    pr = temp;
    temp = temp -> nxt;
  }
  PF("%d IS NOT PRESENT IN LINKED LIST.", pos);
}

void reverse(struct cnode * te) {
  if (te == NULL) {
    return;
  }
  reverse(te -> nxt);
  PF("->%d\t", te -> info);
}

void display() {
  struct cnode * t;
  if (start == NULL) {
    PF("List is not available");
    return;
  }
  t = start;
  PF("\nSTART->");
  while (t != NULL) {
    PF("%d->", t -> info);
    t = t -> nxt;
  }
  PF("NULL");
}
void erase() {
  struct cnode * t;
  if (start == NULL) {
    PF("List is not available");
    return;
  }
  t = start;
  while (start != NULL) {
    t = start;
    start = start -> nxt;
    free(t);
  }
  PF("linked list is destroyed");
}
void insasc() {
  int n, i;
  struct cnode * t;
  PF("Enter how much nodes you want to create ");
  SF("%d", & n);
  for (i = 1; i <= n; i++) {
    newnode();
    if (start == NULL || cur -> info <= start -> info) {
      cur -> nxt = start;
      start = cur;
      //  PF("\n%d is inserted according to priority",cur->d);
    } else {
      t = start;
      //we have to locate t in a such a way that cur->p
      //should be greater than t->p
      while (t -> nxt != NULL && t -> nxt -> info <= cur -> info)
        t = t -> nxt;
      cur -> nxt = t -> nxt;
      t -> nxt = cur;
    }
  }
  PF("\nLinked list is created.");
}
void insdesc() {
  int n, i;
  struct cnode * t;
  start = NULL;
  PF("Enter how much nodes you want to create ");
  SF("%d", & n);
  for (i = 1; i <= n; i++) {
    newnode();
    if (start == NULL || cur -> info >= start -> info) {
      cur -> nxt = start;
      start = cur;
      //  PF("\n%d is inserted according to priority",cur->d);
    } else {
      t = start;
      //we have to locate t in a such a way that cur->p
      //should be greater than t->p
      while (t -> nxt != NULL && t -> nxt -> info >= cur -> info)
        t = t -> nxt;
      cur -> nxt = t -> nxt;
      t -> nxt = cur;
    }
  }
  PF("\nLinked list is created.");
}
void delpos() {
  int i, pos = 0, u = 0;
  struct cnode * ptr, * t;
  if (start == NULL) {
    PF("\nSORRY..CREATE LINKED LIST FIRST");
    return;
  }
  PF("\nENTER POSITION OF NODE YOU WANT TO DELETE");
  SF("%d", & pos);
  t = start;
  while (t != NULL) {
    u++;
    t = t -> nxt;
  }
  if (pos > u) {
    PF("\nNOT A PROPER POSITION TRY AGAI...");
    return;
  }
  t = start;
  if (pos == 1) {
    start = start -> nxt;
    free(t);
    return;
  }
  ptr = start;
  for (i = 1; i < pos; i++) {
    t = ptr;
    ptr = ptr -> nxt;
  }
  t -> nxt = ptr -> nxt;
  free(ptr);
}
void rev() {
  int i;
  struct cnode * p1, * p2, * p3;
  if (start == NULL) {
    PF("\nSORRY..CREATE LINKED LIST FIRST");
    return;
  }
  if (start -> nxt == NULL)
    return;

  p1 = start;
  p2 = p1 -> nxt;
  p3 = p2 -> nxt;
  //1st node becomes last node
  p1 -> nxt = NULL;
  //2nd node points to 1st node
  p2 -> nxt = p1;
  //traverse p3 for reversing
  while (p3 != NULL) {
    p1 = p2;
    p2 = p3;
    p3 = p3 -> nxt;
    p2 -> nxt = p1;
  }
  start = p2;
  PF("\nLINKED LIST IS REVERSED SUCCESSFULLY, PRESS 1 TO DISPLAY LINKED LIST..");
  SF("%d", & i);
  if (i == 1) {
    display();
  }

}
