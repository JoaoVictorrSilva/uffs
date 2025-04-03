import React from "react";
import axios from "axios";
import Header from "../Header";

//style
import "./StyleCadastroLivro.css";

import { Alert, Box, Button, Snackbar, Stack, TextField } from "@mui/material";
import { DataGrid } from "@mui/x-data-grid";

const colunas = [
    { field: "id", headerName: "ID Livro", width: 90 },
    { field: "nome", headerName: "Nome", width: 180 },
    { field: "idEditora", headerName: "ID Editora", width: 180 },
    { field: "idAutor", headerName: "ID Autor", width: 180 },
    { field: "estado", headerName: "Estado", width: 180 },
];

axios.defaults.baseURL = "http://localhost:3010/";
axios.defaults.headers.common["Content-Type"] =
    "application/json;charset=utf-8";

function CadastroLivro() {
    const [nomeL, setNome] = React.useState("");
    const [autorL, setAutor] = React.useState("");
    const [editoraL, setEditora] = React.useState("");
    const [quantidadeL, setQuantidade] = React.useState("");

    const [openMessage, setOpenMessage] = React.useState(false);
    const [messageText, setMessageText] = React.useState("");
    const [messageSeverity, setMessageSeverity] = React.useState("success");

    const [ListaLivros, setListaLivros] = React.useState([]);

    React.useEffect(() => {
        getData();
    }, []);

    async function getData() {
        try {
            const res = await axios.get("/consulta/livros");
            setListaLivros(res.data);
            console.log(res.data);
        } catch (error) {
            setListaLivros([]);
        }
    }

    function clearForm() {
        setNome("");
        setAutor("");
        setEditora("");
        setQuantidade("");
    }

    function handleCancelClick() {
        if (nomeL !== "" || autorL !== "" || editoraL !== "" || quantidadeL !== "") {
            setMessageText("Cadastro do livro cancelado!");
            setMessageSeverity("warning");
            setOpenMessage(true);
        }
        clearForm();
    }

    async function handleSubmit() {
        if (nomeL !== "" && autorL !== "" && editoraL !== "" && quantidadeL !== "") {
            try {
                await axios.post("/livro/cadastro", {
                    nome: nomeL,
                    autor: autorL,
                    editora: editoraL,
                    quantidade: quantidadeL,
                });
                console.log(`Nome: ${nomeL} - Autor: ${autorL} - Editora: ${editoraL} - Quantidade: ${quantidadeL}`);
                setMessageText("Livro cadastrado com sucesso!");
                setMessageSeverity("success");
                clearForm(); // limpa o formulário apenas se cadastrado com sucesso
            } catch (error) {
                console.log(error);
                setMessageText("Falha no cadastro do livro!");
                setMessageSeverity("error");
            } finally {
                setOpenMessage(true);
                await getData();
            }
        } else {
            setMessageText("Dados do livro inválidos!");
            setMessageSeverity("warning");
            setOpenMessage(true);
        }
    }

    function handleCloseMessage(_, reason) {
        if (reason === "clickaway") {
            return;
        }
        setOpenMessage(false);
    }

    return (
        <Box>
            <Header/>
            <Stack className="text" spacing={2}>
                <Stack spacing={2}>
                    <TextField
                        required
                        id="nome-input"
                        label="Nome"
                        size="small"
                        onChange={(e) => setNome(e.target.value)}
                        value={nomeL}
                    />
                    <TextField
                        required
                        id="autor-input"
                        label="Autor"
                        size="small"
                        onChange={(e) => setAutor(e.target.value)}
                        value={autorL}
                    />
                    <TextField
                        required
                        id="editora-input"
                        label="Editora"
                        size="small"
                        onChange={(e) => setEditora(e.target.value)}
                        value={editoraL}
                    />
                    <TextField
                        required
                        id="descr-input"
                        label="Quantidade"
                        size="small"
                        onChange={(e) => setQuantidade(e.target.value)}
                        value={quantidadeL}
                    />
                </Stack>
                <Stack direction="row" spacing={3}>
                    <Button
                        variant="contained"
                        style={{
                            maxWidth: "100px",
                            minWidth: "100px",
                        }}
                        onClick={handleSubmit}
                        type="submit"
                        color="success"
                    >
                        Enviar
                    </Button>
                    <Button
                        variant="outlined"
                        style={{
                            maxWidth: "100px",
                            minWidth: "100px",
                        }}
                        onClick={handleCancelClick}
                        color="error"
                    >
                        Cancelar
                    </Button>
                </Stack>

                <Snackbar
                    open={openMessage}
                    autoHideDuration={6000}
                    onClose={handleCloseMessage}
                >
                    <Alert
                        severity={messageSeverity}
                        onClose={handleCloseMessage}
                    >
                        {messageText}
                    </Alert>
                </Snackbar>
                <Box style={{ height: "500px" }}>
                    <DataGrid rows={ListaLivros} columns={colunas} />
                </Box>
            </Stack>
        </Box>
    );
}

export default CadastroLivro;