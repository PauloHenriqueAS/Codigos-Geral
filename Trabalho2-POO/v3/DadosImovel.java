package Trabalho2;
import java.util.ArrayList;

public class DadosImovel extends Imovel{
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
		}//else if
		else {
			return -1;
		}
	}//fim
	
	
	public void mostarDados(){
		System.out.println("Quantidade de quartos: " + getQtoQuartos());
		System.out.println("Quantidade salas de jantas: " + getQtoSalasJantar());
		System.out.println("Quantidade suítes: " + getQtoSuites());
		System.out.println("Quantidade salas de estar: " + getQtoSalasEstar());
		System.out.println("Quantidade número de vagas garagem: " + getNroVagasGaragem());
		System.out.println("Possui armário embutido: " + isPossuiArmarioEmbutido());
	}
	
							/*Metodos
	public ArrayList<String> pesquisarQtoQuartos(int nroQuartos){}
	public ArrayList<String> pesquisarQtoSalaJantar(int nroSalaJantar){	}
	public ArrayList<String> pesquisarQtoSuite(int nroSuite){}
	public ArrayList<String> pesquisarQtoSalaEstar(int nroSalaEstar){}
	public ArrayList<String> pesquisarNroVagasGaragem(int nroVagas){}
	public ArrayList<String> pesquisarPossuiArmario(boolean armario){}
	*/
	
}
