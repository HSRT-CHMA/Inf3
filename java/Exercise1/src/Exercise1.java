
public class Exercise1 {
	public static void main(String[] args){
		BinärbaumNamen b1 = new BinärbaumNamen("1");
		b1.einfügen("2");
		b1.einfügen("77");
		b1.einfügen("45");
		b1.einfügen("34");
		b1.einfügen("37");
		System.out.println(b1.getHöhe());
		System.out.println(b1.getGrößter());
		System.out.println(b1.getKleinster());
		System.out.println(b1.inOrderAusgabe());
		System.out.println(b1.postOrderAusgabe());
		System.out.println(b1.preOrderAusgabe());
		b1.löschen("34");
		System.out.println(b1.inOrderAusgabe());
	}
}
