package Trabalho2;

import java.util.ArrayList;

public class DadosFormaPagamento {
	private ArrayList<FormaPagamento> vetFormaPagamento = new ArrayList<FormaPagamento>();
	
	public void cadastrar(FormaPagamento c) {
		this.vetFormaPagamento.add(c);
		Persist.salvarBinario("formaPgto.dat", c);//Salvar no arquivo
		System.out.println("Total de formas de pagamentos inseridas: ");
		System.out.println(this.vetFormaPagamento.size());
	}
	
	public void listar(){
		for (FormaPagamento objeto: this.vetFormaPagamento) {
			objeto.mostarDados();
		}
	}
	
	public FormaPagamento buscar(int cod) {
		FormaPagamento c = null;
		for ( FormaPagamento objeto: this.vetFormaPagamento) {
			if (objeto.getCod() == cod) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(int cod){
		FormaPagamento formaPagamentoRemove = this.buscar(cod);
		
		if(formaPagamentoRemove != null) {
			this.vetFormaPagamento.remove(formaPagamentoRemove);
			return true;
		}else {
			return false;
		}
	}
}
