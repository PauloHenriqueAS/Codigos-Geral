package Trabalho2;
import java.io.Serializable;
import java.util.ArrayList;

public class DadosImovel extends Imovel implements PrintDados, Serializable{
	private int qtoQuartos;
	private int qtoSalasJantar;
	private int qtoSuites;
	private int qtoSalasEstar;
	private int nroVagasGaragem;
	private boolean possuiArmarioEmbutido;
	private String descricao;
	
	public DadosImovel(){ }
	
	public DadosImovel(int qtoQuartos, int qtoSalasJantar, int qtoSuites, int qtoSalasEstar, int nroVagasGaragem, boolean possuiArmario, String descricao) {
		setQtoQuartos(qtoQuartos);
		setQtoSalasJantar(qtoSalasJantar);
		setQtoSuites(qtoSuites);
		setQtoSalasEstar(qtoSalasEstar);
		setNroVagasGaragem(nroVagasGaragem);
		setPossuiArmarioEmbutido(possuiArmario);
		setDescricao(descricao);
	}
	
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
	public boolean isPossuiArmarioEmbutido() {
		return possuiArmarioEmbutido;
	}
	public void setPossuiArmarioEmbutido(boolean possuiArmarioEmbutido) {
		this.possuiArmarioEmbutido = possuiArmarioEmbutido;
	}
	public String getDescricao() {
		return descricao;
	}
	public boolean setDescricao(String descricao) {
		if(descricao.length() > 0) {
			this.descricao = descricao;	
			return true;
		}else {
			return false;
		}
	}
	
	public  int calculaIndiceVendaLocacao() {
		String tipo = getTipoLocacao();
		String categoria = getCategoria();
		int baseCasa = 3, baseApto = 2;
		
		if(categoria.equals("casa")) {
			if(tipo.equals("venda")) {
				return baseCasa*2;
			}if(tipo.equals("locacao")) {
				return baseCasa;
			}else {
				return -1;	
			}
		}else if(categoria.equals("apartamento")) {
			if(tipo.equals("venda")) {
				return baseApto*2;
			}if(tipo.equals("locacao")) {
				return baseApto;
			}else {
				return -1;
			}
		}
		else {
			return -1;
		}
	}
	
	
	public void mostarDados(){
		super.mostarDados();
		System.out.println("Quantidade de quartos: " + getQtoQuartos());
		System.out.println("Quantidade salas de jantas: " + getQtoSalasJantar());
		System.out.println("Quantidade suítes: " + getQtoSuites());
		System.out.println("Quantidade salas de estar: " + getQtoSalasEstar());
		System.out.println("Quantidade número de vagas garagem: " + getNroVagasGaragem());
		System.out.println("Possui armário embutido: " + isPossuiArmarioEmbutido());
	}
	
				/*Busca-Excluir-Cadastrar-Listar*/
	private ArrayList<Imovel> vetImovel = new ArrayList<Imovel>();
	
	public void cadastrar(Imovel c) {
		this.vetImovel.add(c);
		Persist.salvarBinario("imovel.dat", c);//Salvar no arquivo
		System.out.println("Total de imoveis inseridos: ");
		System.out.println(this.vetImovel.size());
	}
	
	public void listar(){
		for (Imovel objeto: this.vetImovel) {
			objeto.mostarDados();
		}
	}
	
	public Imovel buscar(int id) {
		Imovel c = null;
		for ( Imovel objeto: this.vetImovel) {
			if (objeto.getIdImovel() == id) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(int id){
		Imovel imovelRemove = this.buscar(id);
		
		if(imovelRemove != null) {
			this.vetImovel.remove(imovelRemove);
			return true;
		}else {
			return false;
		}
	}
	
}
