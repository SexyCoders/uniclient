export default function getUniClientLogo()
  {
    var logo="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";
  return logo;
  }
