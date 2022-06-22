#define _CRT_SECURE_NO_WARNINGS
#pragma comment (lib, "libmysql.lib")

#include <winsock.h>
#include <windows.h>
#include <mysql.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mysqlip "127.0.0.1"
#define port 3306
#define loginusername "bms"
#define loginpassword "1234"
#define mysqlname "bms"

#define TITLE_LENGTH 100

typedef struct bookInfo {
    int id;
    char title[TITLE_LENGTH];
    char writer[TITLE_LENGTH];
    char genre[50];
    char release_date[11];
    int pages;
    char company[50];
    int price;
} book;

void connect_db(MYSQL*);
void close_db(MYSQL*);
// å���� �Է�
void insert_book(MYSQL*, book*);
// å���� ��ȸ
void display_books(MYSQL*);
// å���� ����
void update_book(MYSQL*, book*);
// å���� ����
void delete_book(MYSQL*, book*);
// å���� �˻�
void search_book(MYSQL*, book*);
void print_header(void);

int main() {
    setlocale(LC_ALL, "Korean");
    MYSQL* conn = mysql_init(NULL);
    MYSQL_RES* result;
    MYSQL_ROW row;
    int query_stat;
    unsigned int num_fields;
    unsigned long* lengths;
    int input = 0;

    book myBook;

    connect_db(conn);
    while (1) {
        system("cls");
        printf("�������� ���α׷� v2.0\n");
        printf("1. ���� ��ȸ\n");
        printf("2. ���� �Է�\n");
        printf("3. ���� ����\n");
        printf("4. ���� �˻�\n");
        printf("5. ���� ����\n");
        printf("6. ���α׷� ����\n");
        printf("�Է� > ");
        scanf("%d", &input);
        rewind(stdin);

        switch (input) {
        case 1:
            display_books(conn);
            system("pause");
            break;
        case 2:
            insert_book(conn, NULL);
            system("pause");
            break;
        case 3:
            update_book(conn, NULL);
            system("pause");
            break;
        case 4:
            search_book(conn, NULL);
            system("pause");
            break;
        case 5:
            delete_book(conn, NULL);
            system("pause");
            break;
        case 6:
            close_db(conn);
            exit(0);
        }
    }
}
void connect_db(MYSQL* conn) {
    mysql_real_connect(conn, mysqlip, loginusername, loginpassword, mysqlname, port, NULL, 0);

    if (conn == NULL) {
        fprintf(stderr, "�������! : %s\n", mysql_error(conn));
        return EXIT_FAILURE;
    }

    printf("���Ἲ��!\n");
    printf("�������� %s\n", conn->server_version);

}
void close_db(MYSQL* conn) {
    mysql_close(conn);
    printf("��������\n");
    system("pause");

}
void display_books(MYSQL* conn) {
    int i = 0;
    MYSQL_RES* result;
    MYSQL_ROW row;
    int query_stat;
    unsigned int num_fields;
    unsigned long* lengths;

    query_stat = mysql_query(conn, "SELECT * FROM books_info");
    if (query_stat != 0) {
        fprintf(stderr, "�Է¿���! : %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }
    print_header();

    result = mysql_store_result(conn);
    num_fields = mysql_num_fields(result);
    while (row = mysql_fetch_row(result)) {
        lengths = mysql_fetch_lengths(result);
        for (i = 0; i < num_fields; i++)
        {
            printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

}
void delete_book(MYSQL* conn, book* delbook) { // ���� 
    int i = 0;
    char query[500] = { 0, };
    MYSQL_RES* result;
    MYSQL_ROW row;
    int query_stat = 0;
    unsigned int num_fields;
    unsigned long* lengths;
    book tmpBook = { 0, };

    char title[TITLE_LENGTH];
    char writer[TITLE_LENGTH];
    char genre[50];
    char release_date[15];
    char pages[15];
    char company[50];
    char price[10];
    display_books(conn);
    printf("������ å��ȣ �Է� : ");
    scanf("%d", &tmpBook.id);

    sprintf(query,
        "DELETE FROM books_info WHERE id = %d", tmpBook.id);

    query_stat = mysql_query(conn, query);
    if (query_stat != 0) {
        fprintf(stderr, "��������! : %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }
    /* result = mysql_store_result(conn);
     if (result->row_count == 0) {
         printf("������ �����Ͱ� �����ϴ�.");
     }*/
    printf("å ������ �����Ǿ����ϴ�. \n");
}
void update_book(MYSQL* conn, book* upbook) {
    int i = 0;
    char query[500] = { 0, };
    MYSQL_RES* result;
    MYSQL_ROW row;
    int query_stat = 0;
    unsigned int num_fields;
    unsigned long* lengths;

    char title[TITLE_LENGTH];
    char writer[TITLE_LENGTH];
    char genre[50];
    char release_date[11];
    char pages[15];
    char company[50];
    char price[10];
    book tmpBook = { 0, };

    printf("������ å��ȣ �Է� : ");
    scanf("%d", &tmpBook.id);
    rewind(stdin);

    sprintf(query,
        "SELECT title, writer, genre, release_date, pages, company, price FROM books_info "
        " WHERE id = %d ", tmpBook.id);

    query_stat = mysql_query(conn, query);
    if (query_stat != 0) {
        fprintf(stderr, "�Է¿���! : %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    printf("��������\n");
    result = mysql_store_result(conn);
    print_header();
    num_fields = mysql_num_fields(result);
    while (row = mysql_fetch_row(result)) {
        lengths = mysql_fetch_lengths(result);
        for (i = 0; i < num_fields; i++)
        {
            printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
        }
        printf("\n");
        rewind(stdin);
    }

    printf("���� å�̸�(�ʼ�) : ");
    scanf("%[^\n]s", tmpBook.title);
    rewind(stdin);

    printf("���� ���ڸ�(�ʼ�) : ");
    scanf("%[^\n]s", tmpBook.writer);
    rewind(stdin);

    printf("���� �帣 : ");
    scanf("%[^\n]s", tmpBook.genre);
    rewind(stdin);

    printf("���� ������ : ");
    scanf("%[^\n]s", tmpBook.release_date);
    rewind(stdin);

    printf("���� �������� : ");
    scanf("%d", &tmpBook.pages);
    rewind(stdin);

    printf("���� ���ǻ� : ");
    scanf("%[^\n]s", tmpBook.company);
    rewind(stdin);

    printf("���� ���� : ");
    scanf("%d", &tmpBook.price);
    rewind(stdin);

    sprintf(query,
        " UPDATE books_info SET "
        " title = '%s', writer = '%s' ,genre = '%s', release_date = '%s' "
        " , pages = %d, company = '%s', price = %d WHERE id = %d ",
        tmpBook.title, tmpBook.writer, tmpBook.genre, tmpBook.release_date, tmpBook.pages,
        tmpBook.company, tmpBook.price, tmpBook.id);

    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "�Է¿���! : %s\n", mysql_error(conn));
    }
    printf("å ������ �����Ǿ����ϴ�. \n");
}
void insert_book(MYSQL* conn, book* instbook) {
    int i, j = 0;
    char query[500] = { 0, };
    book tmpBook = { 0, };

    printf("å�̸�(�ʼ�) : ");
    scanf("%[^\n]s", tmpBook.title);
    rewind(stdin);

    printf("���ڸ�(�ʼ�) : ");
    scanf("%[^\n]s", tmpBook.writer);
    rewind(stdin);

    printf("�帣 : ");
    scanf("%[^\n]s", tmpBook.genre);
    rewind(stdin);

    printf("������(�ʼ�, ex, 2010-01-30) : ");
    scanf("%s", tmpBook.release_date);
    rewind(stdin);

    printf("��������(�ʼ�, ex, 200) : ");
    scanf("%d", &tmpBook.pages);
    rewind(stdin);

    printf("���ǻ� : ");
    scanf("%[^\n]s", tmpBook.company);
    rewind(stdin);

    printf("����(�ʼ�, ex, 15000) : ");
    scanf("%d", &tmpBook.price);
    rewind(stdin);

    sprintf(query,
        "INSERT INTO books_info (title, writer, genre, release_date, pages, company, price) "
        " VALUES ('%s', '%s', '%s', '%s', %d, '%s', %d) ",
        tmpBook.title, tmpBook.writer, tmpBook.genre, tmpBook.release_date,
        tmpBook.pages, tmpBook.company, tmpBook.price);

    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "�Է¿���! : %s\n", mysql_error(conn));
    }
    printf("å ������ �ԷµǾ����ϴ�. \n");
}
void search_book(MYSQL* conn, book* searbook) {
    MYSQL_RES* result;
    MYSQL_ROW row;
    int query_stat;
    unsigned int num_fields;
    unsigned long* lengths;
    book tmpBook = { 0, };
    int i = 0;
    char query[500] = { 0, };

    printf("�˻� å�̸�(�ʼ�) : ");
    scanf("%[^\n]s", tmpBook.title);
    rewind(stdin);

    sprintf(query, "SELECT * FROM books_info WHERE title LIKE '%%%s%%' ", tmpBook.title);
    query_stat = mysql_query(conn, query);
    if (query_stat != 0) {
        fprintf(stderr, "����� �����Ͱ� �����ϴ�.! : %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    result = mysql_store_result(conn);
    print_header();
    num_fields = mysql_num_fields(result);
    while (row = mysql_fetch_row(result)) {
        lengths = mysql_fetch_lengths(result);
        for (i = 0; i < num_fields; i++)
        {
            printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

}
void print_header(void) {
    printf("[��ȣ] [å����]  [����]  [�帣]  [������]  [��������]  [���ǻ�]  [����]\n");
    printf("=========================================================================\n");
}
