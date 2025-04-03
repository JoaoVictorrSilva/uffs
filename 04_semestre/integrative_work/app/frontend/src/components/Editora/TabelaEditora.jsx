import React from "react";
import axios from "axios";
import Header from "../Header";

//style
import "./StyleTabelaEditora.css";

import { Box, Stack } from "@mui/material";
import { DataGrid } from "@mui/x-data-grid";

const colunas = [
  { field: "id", headerName: "ID Editora", width: 90 },
  { field: "nome", headerName: "Nome", width: 180 },
];

axios.defaults.baseURL = "http://localhost:3010/";
axios.defaults.headers.common["Content-Type"] =
    "application/json;charset=utf-8";

function TabelaEditora() {
    const [ListaEditoras, setListaEditoras] = React.useState([]);

    React.useEffect(() => {
        getData();
    }, []);

    async function getData() {
        try {
            const res = await axios.get("/editora/consultas");
            setListaEditoras(res.data);
            console.log(res.data);
        } catch (error) {
          setListaEditoras([]);
        }
    }

    return (
        <Box>
            <Header/>
            <Stack className="text" spacing={2}>
                <Box style={{ height: "500px" }}>
                    <DataGrid rows={ListaEditoras} columns={colunas} />
                </Box>
            </Stack>
        </Box>
    );
}

export default TabelaEditora;