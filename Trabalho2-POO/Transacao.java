package Trabalho2;

import java.time.LocalDate;

public class Transacao {
	private LocalDate dataRealizada;
	private int nroContrato;
	private FormaPagamento formaPgto;
	private double valorReal;
	private static int nextContrato = 1;
	
	public Transacao () { }
	
	public Transacao(int nroContrato, FormaPagamento forma, double valReal) {
		this.dataRealizada = LocalDate.now();
		setNroContrato(nroContrato);
		setFormaPgto(forma);
		setValorReal(valReal);
	}
	
	public LocalDate getDataRealizada() {
		return dataRealizada;
	}
	
	public int getNroContrato() {
		return nroContrato;
	}
	public void setNroContrato(int nroContrato) {
		//TODO professora o contrato pode ser 1.2.3.4.5 ou tem que ser data.numero
		this.nroContrato = nextContrato;
		nextContrato++;
	}
	public FormaPagamento getFormaPgto() {
		return formaPgto;
	}
	public void setFormaPgto(FormaPagamento formaPgto) {
		this.formaPgto = formaPgto;
	}
	public double getValorReal() {
		return valorReal;
	}
	public boolean setValorReal(double valorReal) {
		if(valorReal > 0) {
			this.valorReal = valorReal;
			return true;
		}else {
			return false;
		}
	}
	
	/*Metodos
	public void registrarTransacao(int nroContrato){}
	public ArrayList<String> consultarNroContrato(int idImovel){}
	public void gerarBoleto(String cpfCliente, float valor){}
	*/
}
