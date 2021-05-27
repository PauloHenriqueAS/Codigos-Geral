package Trabalho2;

import java.io.Serializable;
import java.time.LocalDate;

public abstract class Imovel implements PrintDados, Serializable {
	private int idImovel;
	private byte disponibilidade;
	private String tipoLocacao;
	private String estadoConservacao;
	private String categoria;
	private double valor;
	private double areaMetros;
	private LocalDate dataPublicacao;
	private String vendaLocacao;
	private LocalDate dataConstrucao;
	private Proprietario proprietarios;
	
	public Imovel(){ }
	
	public Imovel(int id, byte disponibilidade, String tipoLocacao, String estadoConservacao, String categoria, double valor, double areaMetros, LocalDate dataPublicacao, String vendaLocacao, LocalDate dataConstrucao, Proprietario proprietarios) {
		setIdImovel(id);
		setDisponibilidade(disponibilidade);
		setTipoLocacao(tipoLocacao);
		setEstadoConservacao(estadoConservacao);
		setCategoria(categoria);
		setValor(valor);
		setAreaMetros(areaMetros);
		setDataPublicacao(dataPublicacao);
		setVendaLocacao(vendaLocacao);
		setDataConstrucao(dataConstrucao);
		this.proprietarios = proprietarios;
	}
	
	public int getIdImovel() {
		return idImovel;
	}
	public void setIdImovel(int idImovel) {
		this.idImovel = idImovel;
	}
	public String isDisponibilidade() {
		if(disponibilidade == 1) {
			return "Ativo";
		}else if(disponibilidade == 2) {
			return "Inativo";
		}else if(disponibilidade == 3) {
			return "Em Uso";
		}else {
			return "Não Encontrado";
		}
		
	}
	public void setDisponibilidade(byte disponibilidade) {
		this.disponibilidade = disponibilidade;
	}
	public String getTipoLocacao() {
		return tipoLocacao;
	}
	public void setTipoLocacao(String tipoLocacao) {
		this.tipoLocacao = tipoLocacao;
	}
	public String getEstadoConservacao() {
		return estadoConservacao;
	}
	public void setEstadoConservacao(String estadoConservacao) {
		this.estadoConservacao = estadoConservacao;
	}
	public String getCategoria() {
		return categoria;
	}
	public void setCategoria(String categoria) {
		this.categoria = categoria;
	}
	public double getValor() {
		return valor;
	}
	public boolean setValor(double valor) {
		if(valor > 0) {
			this.valor = valor;
			return true;
		}else {
			return false;
		}
	}
	public double getAreaMetros() {
		return areaMetros;
	}
	public boolean setAreaMetros(double areaMetros) {
		if(areaMetros > 0) {
			this.areaMetros = areaMetros;
			return true;
		}else {
			return false;
		}
	}
	public LocalDate getDataPublicacao() {
		return dataPublicacao;
	}
	public void setDataPublicacao(LocalDate dataPublicacao) {
		this.dataPublicacao = dataPublicacao;
	}
	public String getVendaLocacao() {
		return vendaLocacao;
	}
	public void setVendaLocacao(String vendaLocacao) {
		this.vendaLocacao = vendaLocacao;
	}
	public LocalDate getDataConstrucao() {
		return dataConstrucao;
	}
	public void setDataConstrucao(LocalDate dataConstrucao) {
		this.dataConstrucao = dataConstrucao;
	}
	
	public abstract int calculaIndiceVendaLocacao();
	
	public void mostarDados(){
		System.out.println("Id do Imóvel: " + getIdImovel());
		System.out.println("Disponibilidade: " + isDisponibilidade());
		System.out.println("Tipo de Locação: " + getTipoLocacao());
		System.out.println("Estado de Conservação: " + getEstadoConservacao());
		System.out.println("Categoria do imóvel: " + getCategoria());
		System.out.println("Valor: " + getValor());
		System.out.println("Área do imóvel: " + getAreaMetros());
		System.out.println("Data da publicação: " + getDataPublicacao());
		System.out.println("Data da Construção: " + getDataConstrucao());
		proprietarios.mostarDados();
	}
	
}