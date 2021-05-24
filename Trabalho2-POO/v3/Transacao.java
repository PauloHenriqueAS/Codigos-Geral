package Trabalho2;

import java.time.LocalDate;

public class Transacao implements PrintDados{
	private LocalDate dataRealizada;
	private int nroContrato;
	private FormaPagamento formaPgto;
	private double valorReal;
	private Imovel imovelTransacao;
	private Cliente cliente;
	private Corretor corretor;
	
	public Transacao () { }
	
	public Transacao(int nroContrato, FormaPagamento forma, double valReal,Imovel imovelTransacao, Cliente cliente, Corretor corretor) {
		this.dataRealizada = LocalDate.now();
		setNroContrato(nroContrato);
		setFormaPgto(forma);
		setValorReal(valReal);
		this.imovelTransacao = imovelTransacao;
		this.cliente = cliente;
		this.corretor = corretor;
	}
	
	public LocalDate getDataRealizada() {
		return dataRealizada;
	}
	
	public int getNroContrato() {
		return nroContrato;
	}
	public void setNroContrato(int nroContrato) {
		this.nroContrato = nroContrato;
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
	
	
	public void efetuarTransacao(){
		imovelTransacao.setDisponibilidade((byte)3);
		
		//mod Corretor
		double aux = corretor.getVendasMes();
		aux+= getValorReal();
		corretor.setVendasMes(aux);
		
		//mod transacao
		//TODO o que mexeremos aqui se ja passamos tudo para o contrutor??
	}
	
	public void mostarDados(){
		
		System.out.println("Data Realizada: " + getDataRealizada());
		System.out.println("Número Contrato: " + getNroContrato());
		System.out.println("Forma de Pagamento: " + getFormaPgto());
		System.out.println("Valor Real: " + getValorReal());
		cliente.mostarDados();
		imovelTransacao.mostarDados();
		corretor.mostarDados();
	}
	/*Metodos
	public ArrayList<String> consultarNroContrato(int idImovel){}
	public void gerarBoleto(String cpfCliente, float valor){}
	*/
}
