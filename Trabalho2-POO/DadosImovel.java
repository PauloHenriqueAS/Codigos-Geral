package Trabalho2;

public class DadosImovel extends Imovel{
	private int qtoQuartos;
	private int qtoSalasJantar;
	private int qtoSuites;
	private int qtoSalasEstar;
	private int nroVagasGaragem;
	private boolean possuiArmárioEmbutido;
	private String descrição;
	
	public int getQtoQuartos() {
		return qtoQuartos;
	}
	public void setQtoQuartos(int qtoQuartos) {
		this.qtoQuartos = qtoQuartos;
	}
	public int getQtoSalasJantar() {
		return qtoSalasJantar;
	}
	public void setQtoSalasJantar(int qtoSalasJantar) {
		this.qtoSalasJantar = qtoSalasJantar;
	}
	public int getQtoSuites() {
		return qtoSuites;
	}
	public void setQtoSuites(int qtoSuites) {
		this.qtoSuites = qtoSuites;
	}
	public int getQtoSalasEstar() {
		return qtoSalasEstar;
	}
	public void setQtoSalasEstar(int qtoSalasEstar) {
		this.qtoSalasEstar = qtoSalasEstar;
	}
	public int getNroVagasGaragem() {
		return nroVagasGaragem;
	}
	public void setNroVagasGaragem(int nroVagasGaragem) {
		this.nroVagasGaragem = nroVagasGaragem;
	}
	public boolean isPossuiArmárioEmbutido() {
		return possuiArmárioEmbutido;
	}
	public void setPossuiArmárioEmbutido(boolean possuiArmárioEmbutido) {
		this.possuiArmárioEmbutido = possuiArmárioEmbutido;
	}
	public String getDescrição() {
		return descrição;
	}
	public void setDescrição(String descrição) {
		this.descrição = descrição;
	}
	
	
}
