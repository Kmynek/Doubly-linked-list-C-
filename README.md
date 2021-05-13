# Doubly-linked-list-C- Program pozwalający użytkownikowi na wykonywanie dowolnej operacji na liście dwukierunkowej z poziomu konsoli (menu tekstowe).



struct doubly_linked_list_t
{
  struct node_t *head;
  struct node_t *tail;
};

struct node_t
{
  int data;
  struct node_t *next;
  struct node_t *prev;
};

gdzie:
head - wskaźnik na pierwszy element listy, jeżeli lista jest pusta powinien być ustawiony na NULL,
tail - wskaźnik na ostatni element listy, jeżeli lista jest pusta powinien być ustawiony na NULL.
next - wskaźnik na następny element listy, jeżeli nie ma następnego elementu to NULL
prev - wskaźnik na poprzedni element listy, jeżeli nie ma poprzedniego elementu to NULL,
data - wartość przechowywana w elemencie listy


struct doubly_linked_list_t* dll_create();

int dll_push_back(struct doubly_linked_list_t* dll, int value);
int dll_push_front(struct doubly_linked_list_t* dll, int value);
int dll_pop_front(struct doubly_linked_list_t* dll, int *err_code);
int dll_pop_back(struct doubly_linked_list_t* dll, int *err_code);

int dll_back(const struct doubly_linked_list_t* dll, int *err_code);
int dll_front(const struct doubly_linked_list_t* dll, int *err_code);

struct node_t* dll_begin(struct doubly_linked_list_t* dll);
struct node_t* dll_end(struct doubly_linked_list_t* dll);

int dll_size(const struct doubly_linked_list_t* dll);
int dll_is_empty(const struct doubly_linked_list_t* dll);

int dll_at(const struct doubly_linked_list_t* dll, unsigned int index, int *err_code);

int dll_insert(struct doubly_linked_list_t* dll, unsigned int index, int value);
int dll_remove(struct doubly_linked_list_t* dll, unsigned int index, int *err_code);

void dll_clear(struct doubly_linked_list_t* dll);

void dll_display(const struct doubly_linked_list_t* dll);
void dll_display_reverse(const struct doubly_linked_list_t* dll);
Deklaracje wszystkich funkcji oraz struktur w pliku nagłówkowym doubly_linked_list.h, a definicje w pliku doubly_linked_list.c.

struct doubly_linked_list_t* dll_create();
Funkcja przydziela pamięć na strukturę doubly_linked_list_t, inicjuje ją na pustą listę dwukierunkową i zwraca adres przydzielonej struktury. Jeżeli operacja się nie powiedzie to zwraca NULL.

int dll_push_back(struct doubly_linked_list_t* dll, int value);
int dll_push_front(struct doubly_linked_list_t* dll, int value);
Funkcje dodają element o wartości value na koniec (push_back) lub początek (push_front) listy dll. Funkcje zwracają:

0 w przypadku sukcesu,
1 w przypadku błędnych danych wejściowych lub
2 jeżeli nie uda się przydzielić pamięci.
int dll_pop_front(struct doubly_linked_list_t* dll, int *err_code);
int dll_pop_back(struct doubly_linked_list_t* dll, int *err_code);
Funkcje usuwają pierwszy (pop_front) lub ostatni (pop_back) element z listy dll zwracając jego wartość. Do zmiennej err_code, o ile to możliwe, jest zapisywany kod błędu:

0 w przypadku sukcesu,
1 w przypadku błędnych danych wejściowych.
int dll_front(const struct doubly_linked_list_t* dll, int *err_code);
int dll_back(const struct doubly_linked_list_t* dll, int *err_code);
Funkcje zwracają wartość pierwszego (front) lub ostatniego (back) elementu z listy dll bez usuwania tego elementu. Do zmiennej err_code, o ile to możliwe, zapisany zostanie kod błędu:

0 w przypadku sukcesu,
1 w przypadku błędnych danych wejściowych.
struct node_t* dll_begin(struct doubly_linked_list_t* dll);
struct node_t* dll_end(struct doubly_linked_list_t* dll);
Funkcje zwracają:

wskaźnik na pierwszy (begin) lub ostatni (end) elementu listy dll lub
NULL jeżeli nie będzie to możliwe.
int dll_size(const struct doubly_linked_list_t* dll);
Funkcja zwraca:

liczbę elementów w liście dll lub
-1 w przypadku błędnych danych wejściowych.
int dll_is_empty(const struct doubly_linked_list_t* dll);
Funkcja sprawdza czy lista dll jest pusta. Funkcja zwraca:

1 jeżeli lista jest pusta,
0 jeżeli w liście znajdują się jakieś elementy lub
-1 w przypadku błędnych danych wejściowych.
int dll_at(const struct doubly_linked_list_t* dll, unsigned int index, int *err_code);
Funkcja zwraca wartość elementu spod indeksu index listy dll. Indeks elementu liczony jest względem pierwszego elementu (head). Do zmiennej err_code, o ile to możliwe, zapisywany jest kod błędu:

0 w przypadku sukcesu,
1 w przypadku błędnych danych wejściowych.
int dll_insert(struct doubly_linked_list_t* dll, unsigned int index, int value);
Funkcja dodają element o wartości value na pozycję index listy dll. Funkcja zwraca:

0 w przypadku sukcesu,
1 w przypadku błędnych danych wejściowych lub
2 jeżeli nie uda się przydzielić pamięci.
