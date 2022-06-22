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
// 책정보 입력
void insert_book(MYSQL*, book*);
// 책정보 조회
void display_books(MYSQL*);
// 책정보 수정
void update_book(MYSQL*, book*);
// 책정보 삭제
void delete_book(MYSQL*, book*);
// 책정보 검색
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
        printf("도서관리 프로그램 v2.0\n");
        printf("1. 도서 조회\n");
        printf("2. 도서 입력\n");
        printf("3. 도서 수정\n");
        printf("4. 도서 검색\n");
        printf("5. 도서 삭제\n");
        printf("6. 프로그램 종료\n");
        printf("입력 > ");
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
        fprintf(stderr, "연결오류! : %s\n", mysql_error(conn));
        return EXIT_FAILURE;
    }

    printf("연결성공!\n");
    printf("서버버전 %s\n", conn->server_version);

}
void close_db(MYSQL* conn) {
    mysql_close(conn);
    printf("연결종료\n");
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
        fprintf(stderr, "입력오류! : %s\n", mysql_error(conn));
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
void delete_book(MYSQL* conn, book* delbook) { // 삭제 
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
    printf("삭제할 책번호 입력 : ");
    scanf("%d", &tmpBook.id);

    sprintf(query,
        "DELETE FROM books_info WHERE id = %d", tmpBook.id);

    query_stat = mysql_query(conn, query);
    if (query_stat != 0) {
        fprintf(stderr, "쿼리오류! : %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }
    /* result = mysql_store_result(conn);
     if (result->row_count == 0) {
         printf("삭제할 데이터가 없습니다.");
     }*/
    printf("책 정보가 삭제되었습니다. \n");
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

    printf("수정할 책번호 입력 : ");
    scanf("%d", &tmpBook.id);
    rewind(stdin);

    sprintf(query,
        "SELECT title, writer, genre, release_date, pages, company, price FROM books_info "
        " WHERE id = %d ", tmpBook.id);

    query_stat = mysql_query(conn, query);
    if (query_stat != 0) {
        fprintf(stderr, "입력오류! : %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    printf("기존정보\n");
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

    printf("변경 책이름(필수) : ");
    scanf("%[^\n]s", tmpBook.title);
    rewind(stdin);

    printf("변경 저자명(필수) : ");
    scanf("%[^\n]s", tmpBook.writer);
    rewind(stdin);

    printf("변경 장르 : ");
    scanf("%[^\n]s", tmpBook.genre);
    rewind(stdin);

    printf("변경 출판일 : ");
    scanf("%[^\n]s", tmpBook.release_date);
    rewind(stdin);

    printf("변경 페이지수 : ");
    scanf("%d", &tmpBook.pages);
    rewind(stdin);

    printf("변경 출판사 : ");
    scanf("%[^\n]s", tmpBook.company);
    rewind(stdin);

    printf("변경 가격 : ");
    scanf("%d", &tmpBook.price);
    rewind(stdin);

    sprintf(query,
        " UPDATE books_info SET "
        " title = '%s', writer = '%s' ,genre = '%s', release_date = '%s' "
        " , pages = %d, company = '%s', price = %d WHERE id = %d ",
        tmpBook.title, tmpBook.writer, tmpBook.genre, tmpBook.release_date, tmpBook.pages,
        tmpBook.company, tmpBook.price, tmpBook.id);

    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "입력오류! : %s\n", mysql_error(conn));
    }
    printf("책 정보가 수정되었습니다. \n");
}
void insert_book(MYSQL* conn, book* instbook) {
    int i, j = 0;
    char query[500] = { 0, };
    book tmpBook = { 0, };

    printf("책이름(필수) : ");
    scanf("%[^\n]s", tmpBook.title);
    rewind(stdin);

    printf("저자명(필수) : ");
    scanf("%[^\n]s", tmpBook.writer);
    rewind(stdin);

    printf("장르 : ");
    scanf("%[^\n]s", tmpBook.genre);
    rewind(stdin);

    printf("출판일(필수, ex, 2010-01-30) : ");
    scanf("%s", tmpBook.release_date);
    rewind(stdin);

    printf("페이지수(필수, ex, 200) : ");
    scanf("%d", &tmpBook.pages);
    rewind(stdin);

    printf("출판사 : ");
    scanf("%[^\n]s", tmpBook.company);
    rewind(stdin);

    printf("가격(필수, ex, 15000) : ");
    scanf("%d", &tmpBook.price);
    rewind(stdin);

    sprintf(query,
        "INSERT INTO books_info (title, writer, genre, release_date, pages, company, price) "
        " VALUES ('%s', '%s', '%s', '%s', %d, '%s', %d) ",
        tmpBook.title, tmpBook.writer, tmpBook.genre, tmpBook.release_date,
        tmpBook.pages, tmpBook.company, tmpBook.price);

    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "입력오류! : %s\n", mysql_error(conn));
    }
    printf("책 정보가 입력되었습니다. \n");
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

    printf("검색 책이름(필수) : ");
    scanf("%[^\n]s", tmpBook.title);
    rewind(stdin);

    sprintf(query, "SELECT * FROM books_info WHERE title LIKE '%%%s%%' ", tmpBook.title);
    query_stat = mysql_query(conn, query);
    if (query_stat != 0) {
        fprintf(stderr, "출력할 데이터가 없습니다.! : %s\n", mysql_error(conn));
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
    printf("[번호] [책제목]  [저자]  [장르]  [출판일]  [페이지수]  [출판사]  [가격]\n");
    printf("=========================================================================\n");
}
