import java.nio.file.AccessDeniedException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

import javax.sql.rowset.CachedRowSet;
import javax.swing.SortOrder;
import java.util.Comparator;
import java.util.List;



public class AdressManager {
    //メニューの作成
    
    public static void main(String[] args) {
        //データlinked
        ArrayList<Adress> array =new ArrayList<Adress>();
         while(true){
        System.out.println("--------アドレス帳システム--------");
        System.out.println("1 アドレスの増加");
        System.out.println("2 アドレスの閲覧");
        System.out.println("3 アドレスの削除");
        System.out.println("4 アドレスの編集");
        System.out.println("5 アドレスの検索");
        System.out.println("6 アドレスのソート");
        System.out.println("7 アドレスの保存");
        System.out.println("0 退出"); 
        System.out.println("操作の番号を入力してください->");     

        Scanner sc =new Scanner(System.in);
        String line=sc.nextLine();
        switch(line){
            case "1": addAddress(array);
            break;
            case "2": showaddress(array);
            break;
            case "3": deleteAddress(array);
            break;
            case "4": updateAddress(array);
            break;
            case "5": lookAddress(array);
            break;
            case "6": sortAddress(array);
            break;
            case "7": System.out.println("操作7");
            break;
            case "0": System.out.println("ご利用ありがとうございました");
            System.exit(0);//jvm退出

        }
        }

        }
    public static void addAddress(ArrayList<Adress> array){
        Scanner sc = new Scanner(System.in);
        System.out.println("名前:");
        String name =sc.nextLine();
        System.out.println("所属:");
        String affiliation =sc.nextLine();
        System.out.println("携帯電話:");
        String mobile_Phone =sc.nextLine();
        System.out.println("固定電話:");
        String landline_phone =sc.nextLine();
        System.out.println("E-mail:");
        String e_Mail =sc.nextLine();
        System.out.println("住所:");
        String address =sc.nextLine();

        Adress s =new Adress();
        s.setName(name);
        s.setAffiliation(affiliation);
        s.setMobile_Phone(mobile_Phone);
        s.setLandline_phone(landline_phone);
        s.setE_Mail(e_Mail);
        s.setAddress(address);

        array.add(s);
        System.out.println("追加しました。");
    
    }
    public static void showaddress(ArrayList<Adress> array){
        if (array.size()==0){
            System.out.println("アドレス情報がない、追加してください");
            return;
        }
        System.out.println("名前\t\t所属\t\t携帯電話\t\t\t固定電話\t\tE-mail\t\t\t住所\t\t");
        for(int i=0;i<array.size();i++){
            Adress s=array.get(i);
            System.out.println(s.getName()+"\t"+s.getAffiliation()+"\t"+s.getMobile_Phone()+"\t"+s.getLandline_phone()+"\t"+s.getE_Mail()+"\t"+s.getAddress());

        }
    }
    public static void deleteAddress(ArrayList<Adress> array){
        Scanner sc=new Scanner(System.in);
        System.out.println("削除するアドレスの名前を入力してください:");
        String name =sc.nextLine();
        int ind =findAddress(array,name);
        if (ind==-1){
            System.out.println("この人の情報が見つかりません");
        }
        else{

        array.remove(ind);
        System.out.println("削除成功");
    }}   
    public static void updateAddress(ArrayList<Adress> array){
        Scanner sc = new Scanner(System.in);
        System.out.println("編集したいアドレスの名前を入力してください:");
        String name=sc.nextLine();

        System.out.println("新しい名前を入力してください:");
        String new_name=sc.nextLine();
        System.out.println("新しい所属を入力してください:");
        String new_affiliation=sc.nextLine();
        System.out.println("新しい携帯電話を入力してください:");
        String new_mobile_Phone =sc.nextLine();
        System.out.println("新しい固定電話を入力してください:");
        String new_landline_phone =sc.nextLine();
        System.out.println("新しいE-mailを入力してください:");
        String new_e_Mail =sc.nextLine();
        System.out.println("新しい住所を入力してください:");
        String new_address =sc.nextLine();

        Adress s=new Adress(); 
        s.setName(new_name);
        s.setAffiliation(new_affiliation);
        s.setMobile_Phone(new_mobile_Phone);
        s.setLandline_phone(new_landline_phone);
        s.setE_Mail(new_e_Mail);
        s.setAddress(new_address);
        int ind=findAddress(array,name);
       
        if (ind==-1){
            System.out.println("この人の情報が見つかりません");
        }
        else{
            array.set(ind, s);
            System.out.println("編集成功しました。");
       
    }}
    public static int findAddress(ArrayList<Adress>  array,String name){
        int index=-1;
        for(int i=0;i<array.size();i++){
            Adress s=array.get(i);
            if(s.getName().equals(name)){
                index=i;
                break;
            }
        }
        return index;

    }
    public static void lookAddress(ArrayList<Adress> array){
        System.out.println("検索アドレスの名前を入力してください:");
        Scanner sc=new Scanner(System.in);
        String name = sc.nextLine();
        int ind=findAddress(array,name);
       
        if (ind==-1){
            System.out.println("この人の情報が見つかりません");
        }
        else{
            System.out.println("名前\t\t所属\t\t携帯電話\t\t\t固定電話\t\tE-mail\t\t\t住所\t\t");
            Adress s=array.get(ind);
            System.out.println(s.getName()+"\t"+s.getAffiliation()+"\t"+s.getMobile_Phone()+"\t"+s.getLandline_phone()+"\t"+s.getE_Mail()+"\t"+s.getAddress());
    }}
    public static void sortAddress(ArrayList<Adress> array){
        System.out.println("ソートの条件を入力してください＞＞1.名前2.所属");
        String f;
        Scanner sc =new Scanner(System.in);
        f=sc.nextLine();
        
        Collections.sort(array, new Comparator<Adress>() {
            String f1=f;
            int flag;
            @Override
            public int compare(Adress o1, Adress o2) {
            	//按名称排序
                if(f1=="1"){
            	flag=o1.getName().compareTo(o2.getName());}   //这是升降，    o2.getName().compareTo(o1.getName()) ---》这是降序    （下面同理）
            	//按年龄排序
        		if(f1=="2") {
                flag=o1.getAffiliation().compareTo(o2.getAffiliation());
                }
                else{
                    System.out.println("正しく入力してください");
                }
                return flag;
        }}
        );

        }
    }