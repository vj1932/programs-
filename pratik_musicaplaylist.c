#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

const int Max_size = 50;

typedef
struct Node{
    char music[50];
    struct Node *prev;
    struct Node *next;
    int is_playing;

}Node;

typedef
struct List{
    Node *first;
    Node *last;
    Node *current;
}List;

void init(List *l){
    l->first = NULL;
    l->last = NULL;
    l->current = NULL;
}

void insert_music(List *l, char music_file[]){
    if(l->first == NULL){
        l->first = (Node*)malloc(sizeof(Node));
        strcpy(l->first->music,music_file);
        l->first->prev = NULL;
        l->first->next = NULL;
        l->first->is_playing = 0;
        l->last = l->first;
        printf("\nYour File %s is inserted Successfully\n" , music_file);
        return;
    }
    Node tmp = (Node)malloc(sizeof(Node));
    strcpy(tmp->music, music_file);
    tmp->is_playing = 0;
    tmp->next = NULL;
    l->last->next = tmp;
    tmp->prev = l->last;
    l->last = tmp;
    l->last->next = l->first;
    l->first->prev = l->last;
    printf("\nYour File %s is inserted Successfully\n" , music_file);

}

int countNode(List *l){
    int count = 1;
    if(l->first == NULL){
        return count - 1;
    }
    if(l->first->next == NULL){
        return count;
    }
    Node *temp = l->first->next;
    while(temp != l->first){
        temp = temp->next;
        count++;
    }
    return count;
}

void display(List l){
    //puts("------------------------------------------");
    if(l.first == NULL){
        printf("List is Empty!!!\n");
        return;
    }
    printf("\nMusic File Are:  ");

    printf("%s  ",l.first->music);

    if(l.first->next){
        Node *temp = l.first->next;
        while(temp != l.first){
            printf("%s  ",temp->music);
            temp = temp->next;
        }
    }
    puts("");
}


void serachAndPlay(List *l , char music_name[]){
   int i = 0;

   int f = 1;

   int c = countNode(l);

   if(l->first == NULL){
        printf("\nList is Empty!!\n");
        return;
   }

   if(l->current != NULL){
        stopMusic(l);
   }

   while(f && i < c){
        if(l->current == NULL){
            l->current = l->first;
        }
        if(l->current->next){
            l->current = l->current->next;
        }
        f = strcasecmp(l->current->music , music_name);
        i++;
   }

   if(i >= c){
        puts("\nSong Not Found!!");
        return;
   }
   startMusic(l);
   printf("\n%s is now Playing\n",l->current->music);

}

void playMusicFile(List *l, int choice){
    static int flg = 0;
    if(choice == 1){
        flg = 1;
    }else if(l->current != NULL){
        flg = 1;
    }
    if(l->first != NULL){
        if(flg){
            if(choice == 1){
                if(l->current != NULL){
                    stopMusic(l);
                }
                l->current = l->first;
                startMusic(l);
                printf("\n%s is Playing Now\n",l->current->music);
            }
            if(choice == 2){
                if(l->current->next){
                    stopMusic(l);
                    l->current = l->current->next;
                    startMusic(l);
                    printf("\n%s is Playing Now\n",l->current->music);
                }else{
                    puts("\nOnly one song is present!!");
                }
            }
            if(choice == 3){
                if(l->current->prev){
                    stopMusic(l);
                    l->current = l->current->prev;
                    startMusic(l);
                    printf("\n%s is Playing Now\n",l->current->music);
                }else{
                    puts("\nOnly one song is present!!");
                }
            }
        }else{
            puts("\nPlease First Play First File!!");
        }
    }else{
        puts("\nList Is Empty!!");
    }
}

void stopMusic(List *l){
    if(l->current){
        l->current->is_playing = 0;
        //printf("\nYour Music File %s is now stopped \n" , l->current->music);
    }
}

void startMusic(List *l){
    if(l->current){
        l->current->is_playing = 1;
        //printf("\nYour Music File %s is now Playing\n" , l->current->music);
    }
}

void deleteByName(List *l , char musicname[]){
    int f = 1;
    int j = 0;
    int i = 0;

    int c = countNode(l);

    int runn_del;

    if(l->first == NULL){
        puts("\nList Is Empty!!");
        return;
    }

    Node *ptr = l->first;

    while(f && i < c && ptr){
        f = strcasecmp(ptr->music , musicname);
        if(f == 0)  break;
        ptr = ptr->next;
        i++;
   }

   if(i >= c){
        puts("\nNot Found!!");
        return;
   }


   if(ptr != l->current){
        if(i == 0){
            delete_at_beginning(l);
            printf("\nYour File is Deleted Successfully \n");
            printf("\nRemaining ");
            return;
        }
        if(i == (c - 1)){
            delete_at_end(l);
            printf("\nYour File is Deleted Successfully \n");
            printf("\nRemaining ");
            return;
        }
        (ptr->prev)->next = ptr->next;
        (ptr->next)->prev = ptr->prev;

        ptr = NULL;
        free(ptr);
        printf("\nYour File is Deleted Successfully \n");
        printf("\nRemaining ");

   } else{
        puts("\nRunning Music Can't Be deleted!!");
        puts("\nEnter 1 for StopMusic");
        puts("\nEnter 0 for goBack");
        scanf("%d",&runn_del);

        if(runn_del == 1){
            stopMusic(l);
            printf("\nNow You Can delete your %s File\n",l->current->music);
            l->current = NULL;

        } else if(runn_del == 0){
            return;
        }
   }




}

void delete_at_end(List *l){
    if(l->first == NULL){
        printf("\nNot Possible!!\n");
        return;
    }
    if(l->last == l->first){
        l->first = NULL;
        l->last = NULL;
        return;
    }
    Node *tmp = l->last;
    l->last = l->last->prev;
    l->last->next = l->first;
    l->first->prev = l->last;
    free(tmp);
}

void delete_at_beginning(List *l){
    if(l->first == NULL){
        printf("\nNot Possible!!\n");
        return;
    }
    if(l->first->next == NULL){
        l->first = NULL;
        l->last = NULL;
        return;
    }
    if(l->first == l->first->next){
        l->first = NULL;
        l->last = NULL;
        return;
    }
    Node *tmp = l->first;
    l->first = l->first->next;
    l->first->prev = l->last;
    l->last->next = l->first;

    tmp = NULL;
    free(tmp);
}

void main(){
    List l;

    init(&l);

    int opt_choice , play_choice;

    char search_music[Max_size];

    char music_name[Max_size];

    char del_music[Max_size];

    puts("\n**** Welcome To Music Player ****\t\n");

    while(1){
        puts("\n*** Menu ****");
        puts("1. Add Music File");
        puts("2. Remove Music File");
        puts("3. Play Music");
        puts("4. Display All Files");
        puts("5. Exit");
        puts("Enter Your Choice:  ");
        scanf("%d",&opt_choice);

        switch(opt_choice){
            case 1:
                puts("Enter Name of Music File");
                fflush(stdin);
                gets(music_name);
                insert_music(&l,music_name);
                break;

            case 2:
                puts("Enter Name of Music File");
                fflush(stdin);
                gets(del_music);
                deleteByName(&l,del_music);
                display(l);
                break;

            case 3:
                puts("------------------------------------------------------------");
                puts("* First time start with first file or specific file only *\n");

                while(1){
                    puts("\n1. Play First File");
                    puts("2. Play Next File");
                    puts("3. Play Previous File");
                    puts("4. Play Specific File");
                    puts("5. Goback");
                    puts("Enter Your Choice");
                    scanf("%d",&play_choice);

                    if(play_choice == 1)
                        playMusicFile(&l,1);

                    else if(play_choice == 2)
                        playMusicFile(&l,2);


                    else if(play_choice == 3)
                        playMusicFile(&l,3);


                    else if(play_choice == 4){
                        printf("\nEnter Your File name:  ");
                        fflush(stdin);
                        gets(search_music);
                        serachAndPlay(&l , search_music);
                    }
                    else{
                        break;
                    }
                }
                break;

            case 4:
                display(l);
                break;

            case 5:
                puts("\n** Visit Again **");
                exit(0);


        }
    }

}
