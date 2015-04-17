
public class Bin�rbaumNamen {

	private KnotenString wurzel=null;
	
	public Bin�rbaumNamen(String s){
		wurzel=new KnotenString(s);
	}
	
	public int getH�he(){
		return getH�heRekursion(0, wurzel);
	}
	
	private int getH�heRekursion(int aktH�he, KnotenString k){
		if(k!=null)
			return Math.max(getH�heRekursion(aktH�he+1, k.getLinks()), getH�heRekursion(aktH�he+1, k.getRechts()));
		return aktH�he;
	}
	
	public String getKleinster(){
		KnotenString k=getKleinster(wurzel);
		if(k==null)
			return null;
		else
			return k.getData();
	}
	
	private KnotenString getKleinster(KnotenString start){
		if(start!=null){
			while(start.getLinks()!=null)
				start=start.getLinks();
		}
		return start;
	}
	
	public String getGr��ter(){
		KnotenString k=getGr��ter(wurzel);
		if(k==null)
			return null;
		else
			return k.getData();
	}
	
	public KnotenString getGr��ter(KnotenString start){
		if(start!=null){
			while(start.getRechts()!=null)
				start=start.getRechts();
		}
		return start;
	}
	
	public KnotenString getKnoten(String s){
		return getKnotenRekursion(wurzel,s);
	}
	
	private KnotenString getKnotenRekursion(KnotenString k, String s){
		if(k==null)
			return null;
		if((s.compareTo(k.getData()))==0)	//gefunden
			return k;
		if((s.compareTo(k.getData()))<0){	//links weiter suchen
			if(k.getLinks()==null)
				return null;
			return getKnotenRekursion(k.getLinks(),s);
		}
		if((s.compareTo(k.getData()))>0){
			if(k.getRechts()==null)
				return null;
			return getKnotenRekursion(k.getRechts(),s);
		}
		return null;
	}
	
	public String preOrderAusgabe(){
		return preOrderRekursion(wurzel);
	}
	
	private String preOrderRekursion(KnotenString k){
		String s=" ";
		if(k==null)
			return "<leer>";
		//W
				s=k.getData();
				s+=" ";
		//L
		if(k.getLinks()!=null)
			s+=preOrderRekursion(k.getLinks());
		//R
		if(k.getRechts()!=null)
			s+=preOrderRekursion(k.getRechts());
		return s+" ";
	}
	
	public String inOrderAusgabe(){
		return inOrderRekursion(wurzel);
	}
	
	private String inOrderRekursion(KnotenString k){
		String s=" ";
		if(k==null)
			return "<leer>";
		//L
		if(k.getLinks()!=null)
			s=inOrderRekursion(k.getLinks());
		//W
		s+=k.getData();
		//R
		if(k.getRechts()!=null)
			s+=inOrderRekursion(k.getRechts());
		return s+" ";
	}
	
	public String postOrderAusgabe(){
		return postOrderRekursion(wurzel);
	}
	
	private String postOrderRekursion(KnotenString k){
		String s=" ";
		if(k==null)
			return "<leer>";
		//L
		if(k.getLinks()!=null)
			s=postOrderRekursion(k.getLinks());
		//R
				if(k.getRechts()!=null)
					s+=postOrderRekursion(k.getRechts());
		//W
		s+=k.getData();
		return s+" ";
	}
	
	public void einf�gen(String s){
		if(wurzel==null)
			wurzel=new KnotenString(s);
		this.einf�genRekursion(wurzel,s);
	}
	
	private void einf�genRekursion(KnotenString k, String s){
		if(k==null)
			k=new KnotenString(s);
		if(wurzel==null)
			wurzel=k;
		else{
			if((s.compareTo(k.getData()))<0){
				if(k.getLinks()!=null)
					einf�genRekursion(k.getLinks(),s);
				else
					k.setLinks(new KnotenString(s));
			}
			if((s.compareTo(k.getData()))>0){
				if(k.getRechts()!=null)
					einf�genRekursion(k.getRechts(),s);
				else
					k.setRechts(new KnotenString(s));
			}
				
		}
	}
	
	public boolean l�schen(String s){
		return l�schenRekursion(wurzel,s,null,false);
	}
	
	private boolean l�schenRekursion(KnotenString k, String s,KnotenString vater, boolean binLinksVomVater){
		if(k==null)
			return false;
		if((s.compareTo(k.getData()))==0){	
			if((k.getLinks()==null)&&(k.getRechts()==null)){	//k ist Blatt also l�schen
				if(vater==null)
					wurzel=null;
				else
					h�ngeUnterVater(vater,binLinksVomVater,null);
				return true;
			}
			//k hat nur rechts einen Unterknoten
			if((k.getLinks()==null)&&(k.getRechts()!=null)){
				if(vater==null)
					wurzel=k.getRechts();
				else
					h�ngeUnterVater(vater,binLinksVomVater,k.getRechts());
				return true;
			}
			//k hat nur Links einen Unterknoten
			if((k.getLinks()!=null)&&(k.getRechts()==null)){
				if(vater==null)
					wurzel=null;
				else
					h�ngeUnterVater(vater,binLinksVomVater,k.getLinks());
					return true;
			}
			//k hat links und rechts Unterknoten
			KnotenString x=getKleinster(k.getRechts());
			System.out.println("X: "+x);
			l�schen(x.getData());
			if(vater==null){
				x.setLinks(wurzel.getLinks());
				x.setRechts(wurzel.getRechts());
				wurzel=x;
			}
			else{
				x.setLinks(k.getLinks());
				x.setRechts(k.getRechts());
				h�ngeUnterVater(vater,binLinksVomVater,x);
			}
		}
		// nicht gefunden: links weitersuchen
		if((s.compareTo(k.getData()))<0){
			if(k.getLinks()==null)
				return l�schenRekursion(k.getLinks(),s,k,true);
		}
		//nichts gefunden: rechts weitersuchen
		if((s.compareTo(k.getData()))>0){
			if(k.getRechts()==null)
				return l�schenRekursion(k.getRechts(),s,k,false);
		}
		return false;
	}
	
	private void h�ngeUnterVater(KnotenString vater, boolean links, KnotenString k){
		if(links)	//das Kind ist links vom Vater
			vater.setLinks(k);
		else		// ist rechts vom Vater
			vater.setRechts(k);
	}
}
