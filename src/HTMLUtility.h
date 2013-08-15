#ifndef HTML_UTILITY_H_
#define HTML_UTILITY_H_

QString HTMLEncode(QString html)
{
    html = html.replace("'", "''");
    html = html.replace("\"", "&quot;");
    html = html.replace("<", "&lt;");
    html = html.replace(">", "&gt;");
    html = html.replace("\n", "<br>");
    html = html.replace("¡°", "&ldquo;");
    html = html.replace("¡±", "&rdquo;");
    return html;
}

QString HTMLDecode(QString html)
{
    html = html.replace("&rdquo;", "¡±");
    html = html.replace("&ldquo;", "¡°");
    html = html.replace("<br>", "\n");
    html = html.replace("&gt;", ">");
    html = html.replace("&lt;", "<");
    html = html.replace("&quot;", "\"");
    html = html.replace("''", "'");
    return html;
}
#endif