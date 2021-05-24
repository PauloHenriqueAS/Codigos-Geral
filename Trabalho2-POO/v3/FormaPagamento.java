package Trabalho2;

public class FormaPagamento {
	private int cod ;
	private String nomeForma;
	
	public FormaPagamento() { }
	public FormaPagamento( String nome,int cod) {
		setCod(cod);
		setNomeForma(nome);
	}
	public int getCod() {
		return cod;
	}
	public void setCod(int cod) {
		this.cod =cod;
	}
	public String getNomeForma() {
		return nomeForma;
	}
	public boolean setNomeForma(String nomeForma) {
		if(nomeForma.length() > 0) {
			this.nomeForma = nomeForma;	
			return true;
		}else {
			return false;
		}
	}
	
	public void mostrarDados() {
		System.out.println("Codigo: " + getCod());
		System.out.println("Nome Forma: " + getNomeForma());
	}
	
	/*Metodos
    public ArrayList<String> consultarFormasPgto(){    }
    public void adicionarFormaPgto(int codForma, String nomeForma){
        Map<codForma, nomeForma>;
    }*/
}
