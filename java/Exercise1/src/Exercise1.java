
public class Exercise1 {
	public static void main(String[] args){
		Bin�rbaumNamen b1 = new Bin�rbaumNamen("1");
		b1.einf�gen("2");
		b1.einf�gen("77");
		b1.einf�gen("45");
		b1.einf�gen("34");
		b1.einf�gen("37");
		System.out.println(b1.getH�he());
		System.out.println(b1.getGr��ter());
		System.out.println(b1.getKleinster());
		System.out.println(b1.inOrderAusgabe());
		System.out.println(b1.postOrderAusgabe());
		System.out.println(b1.preOrderAusgabe());
		b1.l�schen("34");
		System.out.println(b1.inOrderAusgabe());
	}
}
