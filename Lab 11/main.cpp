#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<process.h>

struct tree
{
struct tree *left;
int info;
struct tree *right;
};

void insert(struct tree **ptr,int item)
{
    if(*ptr==NULL){
        *ptr=(struct tree *)malloc(sizeof(struct tree));
        (*ptr)->left=(*ptr)->right=NULL;
        (*ptr)->info=item;
        return;
    }
    else{
        if(item<(*ptr)->info){
                insert(&((*ptr)->left),item);
        }
        else{
        insert(&((*ptr)->right),item);
        }
    return;
    }
}

void delete_tree(struct tree **ptr,int item){
    struct tree *move,*back,*temp;
    if(*ptr==NULL){
        printf("nEmpty tree..............n");
        return;
    }
    else{
        move=*ptr;
        back=move;
        while(move->info!=item){
            back=move;
            if(item<move->info){
                move=move->left;
            }
            else{
                move=move->right;
            }
        }
    if(move->left!=NULL&&move->right!=NULL){
        temp=move->right;
        while(temp->left!=NULL){
            back=temp;
            temp=temp->left;
        }
        move->info=temp->info;
        move=temp;
    }
    if(move->left==NULL&&move->right==NULL){
        if(back->right==move){
            back->right=NULL;
        }

    else{
        back->left=NULL;
    }
    free(move);
    return;
    }

    if(move->left==NULL&&move->right!=NULL){
        if(back->left==move){
            back->left=move->right;
        }
    else{
        back->right=move->right;
        }
    free(move);
    return;
    }

    if(move->left!=NULL&&move->right==NULL){
        if(back->left==move){
            back->left=move->left;
        }
    else{
        back->right=move->left;
    }
    free(move);
    return;
    }
}

}

void preorder(struct tree *ptr){
    struct tree *move;
    move=ptr;
    if(move!=NULL){
        printf(" %d ",move->info);
        preorder(move->left);
        preorder(move->right);
    }
    else
        return;
}

void inorder(struct tree *ptr){
    struct tree *move;
    move=ptr;
    if(move!=NULL){
        inorder(move->left);
        printf(" %d ",move->info);
        inorder(move->right);
    }
    else
    return;
}

void postorder(struct tree *ptr){
    struct tree *move;
    move=ptr;
    if(move!=NULL){
        postorder(move->left);
        postorder(move->right);
        printf(" %d ",move->info);
    }
    else
        return;
}

void main(){
clrscr();
struct tree *root=0;
int item,ch,order;
char choice,ch1;
clrscr();

do{
    printf("\nn____________Tree MENU_______________nn");
    printf("\n i.Insert.n");
    printf("\n d.Delete.n");
    printf("\n n.Inorder.n");
    printf("\n r.Preorder.n");
    printf("\n o.Postorder.n");
    printf("\ne.Exit.n");
    printf("\nEnter your choice : ");
    ch1=getche();
    switch(ch1){
        case 'i':
            scanf("%d",&item);
            insert(&root,item);
            break;
        case 'd':
            scanf("%d",&item);
            delete_tree(&root,item);
            break;
        case 'r': preorder(root);
            break;
            case 'n': inorder(root);
            break;
        case 'o': postorder(root);
            break;
            case 'e': exit(0);
    }
    fflush(stdin);
    }while(ch!=4);
    return 0;
}
