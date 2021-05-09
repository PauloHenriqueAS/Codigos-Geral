package Trabalho2;

public class Terreno extends Imovel {
	private double largura;
	private double comprimento;
	private String	possuiAcliveDeclive;
	
	public double getLargura() {
		return largura;
	}
	public void setLargura(double largura) {
		this.largura = largura;
	}
	public double getComprimento() {
		return comprimento;
	}
	public void setComprimento(double comprimento) {
		this.comprimento = comprimento;
	}
	public String getPossuiAcliveDeclive() {
		return possuiAcliveDeclive;
	}
	public void setPossuiAcliveDeclive(String possuiAcliveDeclive) {
		this.possuiAcliveDeclive = possuiAcliveDeclive;
	}
	
}
