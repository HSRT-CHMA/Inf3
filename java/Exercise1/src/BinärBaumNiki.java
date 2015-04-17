
public class BinärBaumNiki {
	
	private int höhe;
	private KnotenNiki wurzel;
	

	public BinärBaumNiki(Integer i) {
		wurzel = new KnotenNiki(i);
	}

	public void einfügen(Integer i){
		if(wurzel == null){
			wurzel = new KnotenNiki(i);
		} else {
			this.einfügenRekursion(wurzel, i);
		}
	}
	
	private void einfügenRekursion(KnotenNiki k, Integer i){
		if(k == null){
			k = new KnotenNiki(i);
		} 
		if (wurzel == null){
			wurzel = k;
		} else {
			if ((i.compareTo(k.getInhalt())) < 0){ //Inhalt von i ist kleiner als der Inhalt von k
				if(k.getLinks() != null){
					einfügenRekursion(k.getLinks(), i);
				} else {
					k.setLinks(new KnotenNiki(i));
				}
			}
			
			if ((i.compareTo(k.getInhalt())) > 0){ //Inhalt von i ist größer als der Inhalt von k
				if(k.getRechts() != null){
					einfügenRekursion(k.getRechts(), i);
				} else {
					k.setRechts(new KnotenNiki(i));
				}
			}
			
		}
		
	}
	
	public int getHöhe(){
		return getHöheRekursion(0, wurzel);
	}
	
	private int getHöheRekursion(int aktHöhe, KnotenNiki k){
		if(k != null){
			return Math.max(
					getHöheRekursion(aktHöhe + 1, k.getLinks()) 
					, getHöheRekursion(aktHöhe + 1, k.getRechts()));
		}
		return aktHöhe;
	}
	
	public int getKleinster(){
		KnotenNiki k = getKleinster(wurzel);
		if(k == null){
			return 0;
			} else {
				return k.getInhalt();
		}
	}
	
	private KnotenNiki getKleinster(KnotenNiki start){
		if(start != null){
			while(start.getLinks() != null){
				start = start.getLinks();
				} 
			}
		return start;
	}
	
	public KnotenNiki getKnoten(int inhalt){
		return getKnotenRekursion(wurzel, inhalt);
	}
	
	private KnotenNiki getKnotenRekursion(KnotenNiki k, Integer inhalt){
		if(k == null){ 
			return null;}
		if((inhalt.compareTo(k.getInhalt())) == 0){ 
			return k;
		}
		if(inhalt.compareTo(k.getInhalt()) < 0){
			if (k.getLinks() == null){
				return null;
			} return getKnotenRekursion(k.getRechts(), inhalt);
	 }
		if ((inhalt.compareTo(k.getInhalt())) > 0){
			if(k.getRechts() == null){
				return null;
			}
			return getKnotenRekursion(k.getRechts(), inhalt);
		}
		return null;
	}
	
	public String preOrderAusgabe(){
		return preOrder(wurzel);
	}
	
	
	private String preOrder(KnotenNiki wurzel){  //Tiefe durch Rekursion
		String s = "";
		
		if(wurzel == null){
			return "leer";
		}
		
		s += wurzel.getInhalt() + " ";       //W
		
		if(wurzel.getLinks() != null){      //L
			s += preOrder(wurzel.getLinks()) + " ";
		}
		if(wurzel.getRechts() != null){     //R
			s += preOrder(wurzel.getRechts());
		}
		return s;
	}
	
	public String inOrderAusgabe(){
		return inOrder(wurzel);
	}
	
	
	private String inOrder(KnotenNiki wurzel){
		String s = "";
		if(wurzel == null){
			return "leer";
		}
		
		if(wurzel.getLinks() != null){       //L
			s += inOrder(wurzel.getLinks()) + " "; 
		}
		
		s += wurzel.getInhalt() + " ";   //W
		
		if(wurzel.getRechts() != null){       //R
			s += inOrder(wurzel.getRechts()) + " ";
		}
		return s;
	}
	
	public String postOrderAusgabe(){
		return postOrder(wurzel);
	}
	
	
	private String postOrder(KnotenNiki wurzel){
		String s = "";
		
		if(wurzel == null){
			return "leer";
		}
		
		if(wurzel.getLinks() != null){        //L
			s += postOrder(wurzel.getLinks()) + " "; 
		}
		
		if(wurzel.getRechts() != null){   //R
		    s += postOrder(wurzel.getRechts()) + " ";
	    }
		
		s += wurzel.getInhalt() + " ";      //W
		return s;
	}

	@Override
	public String toString() {
		return wurzel.toString();
	}
}
