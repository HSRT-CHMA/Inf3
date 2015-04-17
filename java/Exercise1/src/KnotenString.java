
public class KnotenString {
	private String s=null;
	private KnotenString links=null;
	private KnotenString rechts=null;
	private boolean markiert=false;
	
	public KnotenString (String s){
		this.setData(s);
	}
	
	public String getData(){
		return s;
	}

	public KnotenString getLinks(){
		return links;
	}
	
	public KnotenString getRechts(){
		return rechts;
	}
	
	public void setData(String s){
		this.s=s;
	}
	
	public void setLinks(KnotenString k){
		this.links=k;
	}
	
	public void setRechts(KnotenString k){
		this.rechts=k;
	}
	
	public void setMarkiert(boolean markiert){
		this.markiert=markiert;
	}
	
	public boolean istMarkiert(){
		return markiert;
	}
	
	@Override
	public String toString(){
		if(this.getData()==null)
			return null;
		return this.getData().toString();
	}

}
