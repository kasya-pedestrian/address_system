#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


#define NAME_MAX 10
#define PHONE_MAX 20
#define ADDRESS_MAX 30
#define E_ADDRESS_MAX 30
#define MAX 10//通讯录最大容量

//アドレス情報の構造体
typedef struct information
{
	char name[NAME_MAX];
	char Affiliation[ADDRESS_MAX];
	char Mobile_Phone[PHONE_MAX];
	char landline_phone[PHONE_MAX];
	char E_Mail[E_ADDRESS_MAX];
	char Address[ADDRESS_MAX];
}information;
//
typedef struct contact{
	struct information *data;
	int people;//人数
	int cont;//容量
}contact;


//初期化
void Initialize(struct contact* hint);
void dilatation(contact* hint);
void ReadContact(contact* hint);

//画面
void menu();
//機能
void address_add(struct contact* hint);
void address_show(const struct contact* hint);
void address_delete(struct contact* hint);
void address_Amend(struct contact* hint);
void address_find(const struct contact* hint);
void address_sort(struct contact* hint);
void address_save(contact* hint);
void DisposalContact(struct contact* hint);//破壊



//main関数
int main(void)
{

	menu();
	return 0;
}
//画面
void menu()
{
	struct contact con;
	int input = 0;
	Initialize(&con);
	do
	{
		printf("*****************************************\n");
		printf("******* 1.アドレスの増加 2.アドレスの閲覧 *******\n");
		printf("******* 3.アドレスの削除 4.アドレスの編集 *******\n");
		printf("******* 5.アドレスの検索 6.アドレスのソート *******\n");
		printf("******* 7.アドレスの保存 0.退出 *******\n");
		printf("*****************************************\n");
		printf("操作の番号を入力してください:>\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			address_add(&con);
			break;
		case 2:
			address_show(&con);
			break;
		case 3:
			address_delete(&con);
			break;
		case 4:
			address_Amend(&con);
			break;
		case 5:
			
			address_find(&con);
			break;
		case 6:
			address_sort(&con);
			break;
		case 7:
			 address_save(&con);
		 	break;
		case 0:
			printf("Bye Bye~~\n");
			exit(1);
		default:
			printf("入力内容が違う");
			break;
		}

	} while (input);
	
	
}

//オーバフローの判断
void dilatation(contact* hint)
{
	if (hint->people == hint->cont)
	{
		//拡張二人のメモリー
		struct information* ptr = (struct information*)realloc(hint->data, (hint->cont + 2) * sizeof(struct information));
		if (ptr == NULL)
		{
			printf("メモリー分配失敗\n");
			return;
		}
		else
		{
			hint->data = ptr;
			hint->cont += 2;//二人のメモリーを増加する
			printf("メモリー分配成功\n");
		}
	}
}

//情報がアドレス帳に導入する
void ReadContact(contact* hint){
	FILE* pfIn = fopen("contact.dat", "rb");
	if (pfIn==NULL)
	{
		printf("ReadContact::%s\n", strerror(errno));//導入失敗
		return;
	}

	information tmp = { 0 };
	while (fread(&tmp, sizeof(information), 1, pfIn))//fread　size_t fread(void *buf, size_t size, size_t n, FILE *fp);
	{
		//オーバフローの判断
		dilatation(hint);
		//导入信息
		hint->data[hint->people] = tmp;
		hint->people++;
	}
	//ファイルを閉める
	fclose(pfIn);
	pfIn = NULL;
}

//アドレス帳システムを初期化する
void Initialize(struct contact* hint)
{
	hint->people = 0;//初期化
	hint->cont = MAX;//情報容量
	hint->data = (struct information*)malloc(MAX * sizeof(struct information));
	if (malloc == NULL)
	{
		printf("初期化失敗\n");
		exit(1);//
	}
	ReadContact(hint);
}

//アドレス帳の増加
void address_add(struct contact* hint){
	dilatation(hint);
	printf("名前:>");
	scanf("%s",hint->data[hint->people].name);
	printf("所属:>");
	scanf("%s",hint->data[hint->people].Affiliation);
	printf("携帯電話:>");
	scanf("%s",hint->data[hint->people].Mobile_Phone);
	printf("固定電話:>");
	scanf("%s",hint->data[hint->people].landline_phone);
	printf("E-Mail:>");
	scanf("%s",hint->data[hint->people].E_Mail);
	printf("住所:>");
	scanf("%s",hint->data[hint->people].Address);
	hint->people++;
}
//全部の情報を現れる
void address_show(const struct contact* hint){
	if(hint->people==0){
		printf("アドレス情報がないです。\n");
	}
	else{
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\t\t%-10s\t\t\t\t%-10s\n", "名前", "所属", "携帯電話", "固定電話", "E-mail","住宅");
		int i =0;
		for ( i = 0; i < hint->people; i++)
		{
			printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n",hint->data[i].name,hint->data[i].Affiliation
			,hint->data[i].Mobile_Phone,hint->data[i].landline_phone,hint->data[i].E_Mail,hint->data[i].Address);
		}	
	}
}
//アドレスがあるかどうか確認関数
static int LookupContact(const struct contact* hint, char* name){
	int i=0;
	for ( i = 0; i < hint->people; i++)
	{
		if(strcmp(hint->data[i].name,name)==0){
		return i;
		}
		else{
			return -1;
		}

	}
	
}

//アドレスの削除
void address_delete(struct contact* hint){
	if (hint->people==0)
	{
		printf("アドレス情報がないです。\n");
	}
	else{
		char name[NAME_MAX];
		printf("削除するアドレスの名前を教えてください:>");
		scanf("%s",&name);
		int res =LookupContact(hint,name);
		if (res==-1)
		{
			
			printf("削除失敗、アドレス中で%sの情報がないです\n",name);

		}
		else{
			int j=0;
			for ( j = res; j < hint->people; j++)
			{
				hint->data[j]=hint->data[j+1];

			}
			printf("削除成功、%sの情報もう削除しました",name);
			hint->people--;
		}
	}
	
}
//アドレスの編集
void address_Amend(struct contact* hint){
	if (hint->people==0)
	{
		printf("アドレス情報がないです。\n");
	}
	else{
		char name[NAME_MAX];
		printf("編集するアドレスの名前を教えてください:>");
		scanf("%s",&name);
		int res =LookupContact(hint,name);
		if (res==-1)
		{
			printf("編集失敗、アドレス中で%sの情報がないです",name);

		}
		else{
			printf("修正内容を教えてください:>");
			printf("名前:>");
			scanf("%s", hint->data[res].name);
			printf("所属:>");
			scanf("%s", hint->data[res].Affiliation);
			printf("携帯:>");
			scanf("%d", hint->data[res].Mobile_Phone);
			printf("固定電話:>");
			scanf("%d", hint->data[res].landline_phone);
			printf("E-mail:>");
			scanf("%s", hint->data[res].E_Mail);
			printf("住宅:>");
			scanf("%s", hint->data[res].Address);
			printf("修正成功、%sの情報もう修正しました",name);
	}
	
}
}


//アドレスの検索

void address_find(const struct contact* hint){
	if (hint->people==0)
	{
		printf("アドレス情報がないです。\n");
	}
	else{
		char name[NAME_MAX];
		printf("検索するアドレスの名前を教えてください:>");
		scanf("%s",&name);
		int res =LookupContact(hint,name);
		if (res==-1)
		{
			printf("編集失敗、アドレス中で%sの情報がないです",name);

		}
		else{
			printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\t\t%-10s\t\t\t\t%-10s\n", "名前", "所属", "携帯電話", "固定電話", "E-mail","住宅");
			printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n",hint->data[res].name,hint->data[res].Affiliation
			,hint->data[res].Mobile_Phone,hint->data[res].landline_phone,hint->data[res].E_Mail,hint->data[res].Address);
		}	
}
}

//名前によってソート
static int name_sort(const void* s1, const void* s2)
{
	return strcmp(((struct information*)s1)->name,((struct information*)s2)->name);
}
//所属によってソート
static int affiliation_sort(const void* s1, const void* s2)
{
	return strcmp(((struct information*)s1)->Affiliation,((struct information*)s2)->Affiliation);
}


//アドレスのソート
void address_sort(struct contact* hint){
	int x=1;
	while (x)
	{
		printf("何によってソートしますが（1.名前/2.所属）");
		scanf("%d",&x);
		switch (x)
		{
		case 1:
			qsort(hint->data, hint->people, sizeof(hint->data[0]), name_sort);
			printf("ソート完了しました。");
			x=0;
			break;
		case 2:
			qsort(hint->data, hint->people, sizeof(hint->data[0]),affiliation_sort);
			printf("ソート完了しました。");
			x=0;
			break;
		default:
			break;
		}
	}
}
//アドレスの廃棄
void DisposalContact(struct contact* hint){
	free(hint->data);
	hint->data=NULL;
	hint->people=0;
	hint->cont=0;
}

//保存
void address_save(contact* pc)
{
	FILE* pfOut = fopen("contact.dat", "wb");//二進数
	if (pfOut == NULL)
	{
		printf("save::%s", strerror(errno));
		return;
	}
	
	int i = 0;
	for (i = 0; i < pc->people; i++)
	{
		fwrite(pc->data + i, sizeof(information), 1,pfOut);//二進数の方式導入
	}

	fclose(pfOut);
	pfOut = NULL;
	printf("保存しました。\n");
}




