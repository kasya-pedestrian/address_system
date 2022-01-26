

//学生クラス

public class Adress{
    private String Name;
    private String Affiliation;
    private String Mobile_Phone;
    private String landline_phone;
    private String E_Mail;
    private String Address;
    public Adress() {
    }
    public Adress(String name, String affiliation, String mobile_Phone, String landline_phone, String e_Mail,
            String address) {
        this.Name = name;
        this.Affiliation = affiliation;
        this.Mobile_Phone = mobile_Phone;
        this.landline_phone = landline_phone;
        this.E_Mail = e_Mail;
        this.Address = address;
    }
    public String getName() {
        return Name;
    }
    public void setName(String name) {
        this.Name = name;
    }
    public String getAffiliation() {
        return Affiliation;
    }
    public void setAffiliation(String affiliation) {
        this.Affiliation = affiliation;
    }
    public String getMobile_Phone() {
        return Mobile_Phone;
    }
    public void setMobile_Phone(String mobile_Phone) {
        this.Mobile_Phone = mobile_Phone;
    }
    public String getLandline_phone() {
        return landline_phone;
    }
    public void setLandline_phone(String landline_phone) {
        this.landline_phone = landline_phone;
    }
    public String getE_Mail() {
        return E_Mail;
    }
    public void setE_Mail(String e_Mail) {
        this.E_Mail = e_Mail;
    }
    public String getAddress() {
        return Address;
    }
    public void setAddress(String address) {
        this.Address = address;
    }
    

	/*public int compareTo(Adress array) {
        int x=0;
        int diff=0;
		if (x==0){// 名前による
		    String name1 = this.getName();
		    String name2 = array.getName();
		    diff = name1.compareTo(name2);
    }   
        else{
            String affiliation1 = this.getAffiliation();
		    String affiliation2 = array.getAffiliation();
		    diff = affiliation1.compareTo(affiliation2);
        }

		if(diff >0){    
			return 1;
		}else if(diff == 0){
			return 0;
		}else{
			return -1;
		}

		
	}
*/

}