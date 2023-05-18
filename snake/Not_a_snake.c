#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define inputClean while(getchar()!='\n')

enum userMenu{Start=1,Settings,Exit};
enum settingsMenu{Set_Try=1,Set_Max,Set_Exit};
enum vspomMenu{Vs_Yes=1,Vs_No};

/* Мысли по поводу того что стоит добавить:
Надо будет добавить сохранение данных и возможно таблицу лучших попыток(игроков?)

Взять это как курсач к следущему сему?
Хотя имхо тут уж слишком мелкий код самой игры
Расширить геймплей с поиска одного числа на чот по интересней
Поиск на несколько уровней с созданием динамического массива?
Вообще, развивая эту идею могу из этого вообще простеньку рпг запилить
Образно: 
Уровни/Враги:
Есть обычные, это одномерные массивы(Дают опыт?)

Мини-боссы попадат реже, но после победы восполнят хп(попытки)
Представлят собой двумерную матрицу

Босс
Трехмерная матрица, после победы восполняет хп и даёт бонус, от +макс хп до + к диапазону атаки

Можно прикрутить уровни с условиями, пример:
Горная местность из-за изменения высот числа бьют не всегда точно(+/- к тому что пишешь)
(Образно написал 2, а получил 3 или 1 с некоторым шансом)
(Сам шанс можо менять в зависимости от сложности)

Раз добавляем местность то можно в формате текстовых квестов добавить и передвижение между локами

А тогда и сжет крутануть можно....
Хотя конечно сюжет в игре написанной на си за 3 часа в бк глубже чем "герой пинает всё зло и спасает всё добро"такое...
НО если развивать, то почему бы и не да? Тип графики ноль, берем оригинальностью геймплея и сжеткой
Хотя конечно это и на образной юньке клепануть и можно будет привлечь куда большу аудиторию.....

Название будет бургеркиноговый рыцарь
По сюжету злобный "Аккамулятор" забрал его телефон, заряд с него раскидал по бк в виде монстров 
И теперь наш герой вынужден сражаться с нимим всеми чтобы спасти бк и победить злодея чтобы забрать телефон
Аккуму можно припихать грустну историю про то что люди не ели сидя в бк, а смотрели в телефоны и болтали 
и он решил действовать 
Врагами могут быть как образные баги, так и запчасти еды/ сама еда
Пример: Оставленый бургер
Фраза в начале:
"Они обязательно ещё притронутся ко мне"/"Я ещё свежий, честно" 
Способность(вообще я вижу его монстром первого лвла так что не должно быть, но ради того чтобы показать...):
"Не самый свежий аромат":
Бургер испускает зловонный аромат и заставляет персонажа вместо образной 5 писать 4 или 3(-1 или -2) на пару ходов
(Возможно добавление фраз от бургера вроде "Я ещё свежий, вот, понюхай" или "Э...Это специально запах такой!") 

Вообще механника способностей примитивнейщая, но прикол в том что изначально, никто не знает как они пашут
Т.е. вохможен ап позволящий видеть модификаторы, но изначально придется узнавать как дебафф и его длительность
Ну и плюс сами по себе дебафы не всегда будут +1/-1, там потом с усложнением врагов и функции могут пойти
Ну и сами скилы смогут предположим не активными быть, а стать оч ебнутыми пассивками

кст как вариант сложнейшего/простейшего перса- чел который рандомит вообще всё,и победа над ним-реально ток удача

Ещё можно добавить разну начальну прокачку гг:
тип прогер видит простейшие скилы,
рога бьет два раза за одну жизнь
Воин может не терять жизнь с некоторым шансом

Если брать то надо по больше ООП и графику бы тогда накрутить
На си вообще есть модули для графики?

Кст как вариант пихнуть ещё музыку внутрь через звукрвые сигналы(не оч, так как тяжело и такое)
Или через работу с файлами что звучит уже по прикольнее

Ещё хотелось бы по больше функций и автоматизированности
Тип прям блоки объектов сюда запилить что ли...
Возможна реализация блоков через пользовательские типы данных

Много лишних переменных, конечно можно оставить и с этим костылём, но лучше всё же будет чот придумать
*/

int main(void){
  int cache_tries=10;
  int max_rand=10;
  int max_rand_vspom=max_rand;
  int number=0;
  int tries=10;
  int user_Choice=0;
  int vspom_tries=tries;
  int settings_Choice;
  char user_input;
  while(user_Choice!=Exit){
  puts("User_Menu:\n1)Start\n2)Settings\n3)Exit");
  scanf("%d",&user_Choice);
    switch(user_Choice){
      case Start:
        tries=cache_tries;
        srand(time(NULL));
        number=rand()%max_rand+1;
        user_Choice=Start;
        puts("Game started\nPick a number");
        inputClean;
        if(scanf("%d",&user_input)!=1){
          puts("You lost");
          inputClean;
          break;
          }
        while((user_input!=number)&&(tries>0)){
             if(user_input<number){
              puts("number > than yours");
              tries-=1;
              printf("Tries left: %d\n", tries);
              if(scanf("%d",&user_input)!=1){
                puts("You lost");
                inputClean;
                break;}
            }
          else{
              puts("number < than yours");
              tries-=1;
              printf("Tries left: %d\n", tries);
              if(scanf("%d",&user_input)!=1){
                puts("You lost");
                inputClean;
                break;}
            }
          }
        if(user_input==number){
            puts("You won!\nReturning to main menu....");
          }
        else{
            puts("You lost, but don't give up, try once more!\nReturning to main menu....");
          }
      break;
      case Exit:
        user_Choice=Exit;
        puts("Program end");
        inputClean;
      break;
      case Settings:
        puts("Go to settings?\n1)Yes\n2)No");
        scanf("%d",&settings_Choice);
        switch(settings_Choice){
              case Vs_Yes:
                settings_Choice=1;
              break;
              case Vs_No:
                settings_Choice=Set_Exit;
                inputClean;
                continue;
              break;
              default:
                puts("Something went wrong, try again");
                settings_Choice=Set_Exit;
                inputClean;
                continue;
              break;
          }
        settings_Choice+=1;
        while(settings_Choice!=Set_Exit){
        user_Choice=Settings;
        puts("What do yo want to change:\n1)Number of tries\n2)Max number\n3)Back to menu");
        scanf("%d",&settings_Choice);
        switch (settings_Choice){
        case Set_Try:
            settings_Choice=Set_Try;
            vspom_tries=tries;
            printf("Number of tries at the moment: %d\n", tries);
            puts("Input new number:");
            if((scanf("%d",&tries)==1)&&(tries>0)){
              puts("Succsesfuly input new number");
              cache_tries=tries;
              inputClean; 
              continue;}
            else{
              inputClean;
              puts("Something went wrong, please try again");
              tries=vspom_tries;
              continue;
            }
          break;
        case Set_Max:
            settings_Choice=Set_Max;
            max_rand_vspom=max_rand;
            printf("Max number at the moment: %d\n", max_rand);
            puts("Input new max number:");
            inputClean; 
            if((scanf("%d",&max_rand)==1)&&(max_rand>0)){
              puts("Succsesfuly input new max number");
              continue;
            }
            else{
                inputClean;
              puts("Something went wrong, please try again");
              max_rand=max_rand_vspom;
              continue;
            }
          break;
        case Set_Exit:
              settings_Choice=Set_Exit;
              puts("Going back to main menu....\n");
              inputClean;
          break;
        inputClean;
        default:
            puts("Error 404, nothing found");
            inputClean;
          break;
            }
      }
      break;
      default:
        puts("Error 404, nothing found");
        inputClean;
      break;
    }
    puts("\n");
  }
}
