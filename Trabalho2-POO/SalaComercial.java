package Trabalho2;

public class SalaComercial extends Imovel{
	private int qtdBanheiros;
	private int qtdComodos;
	
	public SalaComercial() {}

	public SalaComercial(int qtdBanheiros, int qtdComodos) {
		setQtdBanheiros(qtdBanheiros);
		setQtdComodos(qtdComodos);
	}
	
	public int getQtdBanheiros() {
		return qtdBanheiros;
	}
	public void setQtdBanheiros(int qtdBanheiros) {
		this.qtdBanheiros = qtdBanheiros;
	}
	public int getQtdComodos() {
		return qtdComodos;
	}
	public void setQtdComodos(int qtdComodos) {
		this.qtdComodos = qtdComodos;
	}
	
	
	/*Metodos
	public ArrayList<String> pesquisarQtoBanheiros(int qtoBanheiro){}
	public ArrayList<String> pesquisarQtoComodos(int qtoComodos){}
	*/
}
