package Trabalho2;

public class FormaPagamento {
	private int cod ;
	private String nomeForma;
	private static int nextCod = 0;
	
	public FormaPagamento() { }
	public FormaPagamento( String nome) {
		setCod();
		setNomeForma(nome);
	}
	public int getCod() {
		return cod;
	}
	public void setCod() {
		this.cod = nextCod;
		nextCod++;
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
	
	/*Metodos
    public ArrayList<String> consultarFormasPgto(){    }
    public void adicionarFormaPgto(int codForma, String nomeForma){
        Map<codForma, nomeForma>;
    }*/
}
