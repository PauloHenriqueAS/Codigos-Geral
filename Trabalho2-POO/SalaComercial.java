package Trabalho2;

import java.io.Serializable;

public class SalaComercial extends Imovel implements PrintDados, Serializable{
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
	
	public int calculaIndiceVendaLocacao() {
		int base =1;
		String tipo = getTipoLocacao();
		if(tipo.equals("venda")) {
			return base*2;
		}if(tipo.equals("locacao")) {
			return base;
		}else {
			return -1;
		}
	}
	
	public void mostarDados(){
		super.mostarDados();
		System.out.println("Quantidade de banheiros: " + getQtdBanheiros());
		System.out.println("Quantidade de cômodos: " + getQtdComodos());
	}
	
}
