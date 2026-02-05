public class per1 {
    String name;
    int age;
    public per1(String n,int a)
    {
        name=n; 
        age=a;
    }
    public void display() {
        System.out.println("name:"+name);
        System.out.println("age:"+age);
    }
    public static void main(String[] args) {
        per1 p1=new per1("john",25);
        per1 p2=new per1("jane",12);
        p1.display();
        p2.display();
    }
}
