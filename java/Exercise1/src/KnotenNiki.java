
public class KnotenNiki {
	
	private KnotenNiki links;
	private KnotenNiki rechts;
	private Integer inhalt;
	
	public KnotenNiki(Integer inhalt){
		this.setInhalt(inhalt);
	}

	public KnotenNiki getLinks() {
		return links;
	}
	public void setLinks(KnotenNiki links) {
		if(links != null){
		this.links = links;
		}
	}
	public KnotenNiki getRechts() {
		return rechts;
	}
	public void setRechts(KnotenNiki rechts) {
		if(rechts != null){
		this.rechts = rechts;
		}
	}
	public int getInhalt() {
		return inhalt;
	}
	public void setInhalt(Integer inhalt) {
		this.inhalt = inhalt;
	}

	@Override
	public String toString(){
		return "Inhalt des Knoten : " + getInhalt();
	}
}
