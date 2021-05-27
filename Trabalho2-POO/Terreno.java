package Trabalho2;

import java.io.Serializable;

public class Terreno extends Imovel implements PrintDados, Serializable{
	private double largura;
	private double comprimento;
	private String	possuiAcliveDeclive;
	
	public Terreno(){ }
	
	public Terreno(double largura, double comprimento, String possuiAcliveDeclive) {
		setLargura(largura);
		setComprimento(comprimento);
		setPossuiAcliveDeclive(possuiAcliveDeclive);
	}
	
	public double getLargura() {
		return largura;
	}
	public boolean setLargura(double largura) {
		if(largura > 0) {
			this.largura = largura;
			return true;
		}else {
			return false;
		}
	}
	public double getComprimento() {
		return comprimento;
	}
	public boolean setComprimento(double comprimento) {
		if(comprimento > 0) {
			this.comprimento = comprimento;
			return true;
		}else {
			return false;
		}
	}
	public String getPossuiAcliveDeclive() {
		return possuiAcliveDeclive;
	}
	public boolean setPossuiAcliveDeclive(String possuiAcliveDeclive) {
		if(possuiAcliveDeclive.length() > 0) {
			this.possuiAcliveDeclive = possuiAcliveDeclive;	
			return true;
		}else {
			return false;
		}	
	}
	
	public  int calculaIndiceVendaLocacao() {
		int base =4;
		String tipo = getTipoLocacao();
		if(tipo.equals("lenda")) {
			return base*2;
		}if(tipo.equals("locacao")) {
			return base;
		}else {
			return -1;
		}
	}
	
	public void mostarDados(){
		super.mostarDados();
		System.out.println("Largura: " + getLargura());
		System.out.println("Comprimento: " + getComprimento());
		System.out.println("Possui Aclive: " + getPossuiAcliveDeclive());
	}
	
}
